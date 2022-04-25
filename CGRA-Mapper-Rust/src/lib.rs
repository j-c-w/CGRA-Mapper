use egg::*;
use std::os::raw::c_char;
use std::mem::size_of;

#[repr(C)]
pub struct CppNode {
	op: *const c_char,

	num_children: u16,
	child_ids: *const u32
}

#[repr(C)]
pub struct CppDFG {
  nodes: *const CppNode,
  count: u32
}

#[repr(C)]
pub struct CppDFGs {
  dfgs: *const CppDFG,
  count: u32
}

fn dfg_to_egraph(dfg: CppDFG) -> (EGraph<SymbolLang, ()>, Vec<Id>) {
	let nodes = unsafe { std::slice::from_raw_parts(dfg.nodes, dfg.count as usize) };
	let mut egraph: EGraph<SymbolLang, ()> = Default::default();
	let mut eclasses = vec![];
    let mut is_root = (0..nodes.len()).map(|_| true).collect::<Vec<_>>(); // could use bit vector
	// DEBUG >>>
	let test = 
	unsafe { std::slice::from_raw_parts(std::ptr::null_mut(), 0) }.iter()
		.map(|&c: &u32| eclasses[c as usize]).collect::<Vec<_>>();
	println!("{:?}", test);
	for (i, node) in nodes.iter().enumerate() {
		let op = Symbol::from(unsafe { std::ffi::CStr::from_ptr(node.op) }.to_str().unwrap());
		println!("{}: {} with children: {:?}", i, op,
			unsafe { std::slice::from_raw_parts(node.child_ids, node.num_children as usize) });
	}
	// <<<
	for node in nodes {
		let op = Symbol::from(unsafe { std::ffi::CStr::from_ptr(node.op) }.to_str().unwrap());
		// DEBUG
		println!("{}: {} with {} children", eclasses.len(), op, node.num_children);
		let children = unsafe { std::slice::from_raw_parts(node.child_ids, node.num_children as usize) }.iter()
			.map(|&c| {
				// DEBUG
				println!("access: {} / {}", c, eclasses.len());
                is_root[c as usize] = false;
				eclasses[c as usize]
			}).collect::<Vec<_>>();
		eclasses.push(egraph.add(SymbolLang::new(op, children)));
	}

    let mut roots = eclasses.iter().cloned().zip(is_root.iter().cloned())
        .filter_map(|(e, is_r)| if is_r { println!("{:?}", egraph[e]); Some(e) } else { None }).collect::<Vec<_>>();
    // we remove duplicates, why is this necessary?
    roots.sort();
    roots.dedup();
	(egraph, roots)
}

fn add_dfg<L: Language, N: Analysis<L>>(dfg: &RecExpr<L>, egraph: &mut EGraph<L, N>) -> Vec<Id> {
    let nodes = dfg.as_ref();
    let mut eclasses = Vec::with_capacity(nodes.len());
    let mut is_root = (0..nodes.len()).map(|_| true).collect::<Vec<_>>(); // could use bit vector
    for node in nodes {
        eclasses.push(egraph.add(node.clone().map_children(|i| {
            is_root[usize::from(i)] = false;
            eclasses[usize::from(i)]
        })));
    }
    eclasses.iter().cloned().zip(is_root.iter().cloned())
        .filter_map(|(e, is_r)| if is_r { Some(e) } else { None }).collect::<Vec<_>>()
}

fn expr_to_dfg(expr: RecExpr<SymbolLang>) -> CppDFG {
	let enodes = expr.as_ref();
	let nodes_ptr = unsafe { libc::malloc(enodes.len() * size_of::<CppNode>()) } as *mut CppNode;
	let nodes = unsafe { std::slice::from_raw_parts_mut(nodes_ptr, enodes.len()) };
	for (en, n) in enodes.iter().zip(nodes.iter_mut()) {
		n.op = std::ffi::CString::new(en.op.as_str()).unwrap().into_raw();
		let child_ids = unsafe { libc::malloc(en.children.len() * size_of::<u32>()) } as *mut u32;
		for (child_id, &c) in unsafe { std::slice::from_raw_parts_mut(child_ids, en.children.len()) }.iter_mut().zip(en.children.iter()) {
			*child_id = usize::from(c).try_into().unwrap();
		}
		n.num_children = en.children.len().try_into().unwrap();
		n.child_ids = child_ids;
	}

	CppDFG { nodes: nodes_ptr, count: enodes.len().try_into().unwrap() }
}

#[no_mangle]
pub extern "C" fn optimize_with_egraphs(dfg: CppDFG) -> CppDFGs {
	println!("entering Rust");

	let rules: &[Rewrite<SymbolLang, ()>] = &[
		// Rules we came up with:
		rewrite!("sub-to-add-neg"; "(sub ?x ?y)" => "(add ?x (neg ?y))"),

		// Rules from GCC (these are from :
		// https://github.com/gcc-mirror/gcc/blob/master/gcc/match.pd commit https://github.com/gcc-mirror/gcc/blob/7690bee9f36ee02b7ad0b8a7e7a3e08357890dc0/gcc/match.pd


		// =======
		// Integer Rules:
		// Line 168:
		// TODO -- how to get the precision (it's a constant --- note that this is sufficient for
		// proof of concept, but not for actually running the code)?
		// (31 is actually meant to be precision - 1).
		rewrite!("abs-expand"; "(abs ?x)" => "(xor (add (rsl (?x 31)) ?x) (rsl ?x (31)))"),
		// Line: 280
		rewrite!("neg-to-mul"; "(neg ?x)" => "(mul ?x -1)"),
		rewrite!("mul-to-neg"; "(mul ?x -1)" => "(neg ?x)"), // TODO -- Thomas: This is cyclical,
		// should we consider it?
		// Line 320: TODO (IMO probably a somewhat useful one) (jcw)
		// Line 368: TODO -- only works for unsigned a.  Is there a way to check for this? (We can
		// probably skp this rule?)
		rewrite!("rsl-to-lsl-div"; "(rsl ?a ?b)" => "(div ?a (lsl 1 ?b))"),
		// Line 401:
		rewrite!("neg-to-div"; "(neg ?x)" => "(div ?x -1)"),
		rewrite!("div-to-neg"; "(div ?x -1)" => "(neg ?x)"), // TODO -- Thomas: this is cyclical,
		// see notes on the mul-to-neg case.

		// Line 422: Maybe useful? x / abs(x) => x < 0 ? -1 : 1?  Maybe too complex to match much?
		
		// Line 585: TODO -- is there a way to make it match constants only?
		// that would make this much simpler, as it could avoid introducing the lsl operation.
		rewrite!("rsl-to-logical-and"; "(rsl ?x ?a)" => "(div (and ?x (neg (2 lsl ?a))) (2 lsl ?a))"),
		// Line 685
		rewrite!("mod-to-neg-div-times"; "(mod ?x ?y)" => "(sub ?x (mul (div ?x ?y) ?y))"), // TODO
		// -- maybe that backwards? (jcw)

		// =========
		// Floating Point Rules.
		// Note that for FP rules, we generally assume -ffast-math or
		// equivlanet.  Otherwise, very limited rules apply, so not worthwhile.
		// Line 539:
		rewrite!("fneg-to-fdiv"; "(fneg ?x)" => "(fdiv ?x -1.0)"),
		rewrite!("fdiv-to-fneg"; "(fdiv ?x -1.0)" => "(fneg ?x)"),
		// Line 544:
		rewrite!("fmul-to-fdiv"; "(fdiv ?a (fmul ?b ?c))" => "(fdiv (fdiv ?a ?b) ?c)"), // Other
		// driection of that may be useful?
		// Line 558:
		rewrite!("fmul-to-fdiv-2"; "(fmul (fdiv ?a ?b) ?c)" => "(fdiv ?a (fdiv ?b ?c))"),

		// TODO --- note that there are a lot of rules around line 700 that may or may not be
		// useful if we encounter library calls to math.h.

		// TODO--- Useful rules copied up to line 1000, copy the remaining rules (jcw)

		// Other standard rules:

		rewrite!("commute-add"; "(add ?x ?y)" => "(add ?y ?x)"),
		rewrite!("commute-mul"; "(mul ?x ?y)" => "(mul ?y ?x)"),

		rewrite!("add-0"; "(add ?x 0)" => "?x"),
		rewrite!("mul-0"; "(mul ?x 0)" => "0"),
		rewrite!("mul-1"; "(mul ?x 1)" => "?x"),
	];

	let (egraph, mut roots) = dfg_to_egraph(dfg);
    println!("identified {} roots", roots.len());
	egraph.dot().to_svg("/tmp/initial.svg").unwrap();

	let runner = Runner::default().with_egraph(egraph).run(rules);
    runner.egraph.dot().to_svg("/tmp/egraph.svg");
    for r in &mut roots[..] {
        *r = runner.egraph.find(*r);
    }
	let (best, bestRoots) = LpExtractor::new(&runner.egraph, AstSize).solve_multiple(&roots[..]);

	{
		let mut g: EGraph<SymbolLang, ()> = Default::default();
		g.add_expr(&best);
		g.dot().to_svg("/tmp/final.svg").unwrap();
	}

	let dfgs_ptr = unsafe { libc::malloc(size_of::<CppDFG>()) } as *mut CppDFG;
	assert!(dfgs_ptr != std::ptr::null_mut());
	unsafe { *dfgs_ptr = expr_to_dfg(best) };
	
	CppDFGs { dfgs: dfgs_ptr, count: 1 }
}
