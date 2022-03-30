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

fn dfg_to_egraph(dfg: CppDFG) -> (EGraph<SymbolLang, ()>, Id) {
	let nodes = unsafe { std::slice::from_raw_parts(dfg.nodes, dfg.count as usize) };
	let mut egraph: EGraph<SymbolLang, ()> = Default::default();
	let mut eclasses = vec![];
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
				eclasses[c as usize]
			}).collect::<Vec<_>>();
		eclasses.push(egraph.add(SymbolLang::new(op, children)));
	}

	let root = *eclasses.last().unwrap(); // root is last node in array?
	(egraph, root)
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
		rewrite!("sub-to-add-neg"; "(sub ?x ?y)" => "(add ?x (neg ?y))"),

		rewrite!("commute-add"; "(add ?x ?y)" => "(add ?y ?x)"),
		rewrite!("commute-mul"; "(mul ?x ?y)" => "(mul ?y ?x)"),

		rewrite!("add-0"; "(add ?x 0)" => "?x"),
		rewrite!("mul-0"; "(mul ?x 0)" => "0"),
		rewrite!("mul-1"; "(mul ?x 1)" => "?x"),
	];

	let (egraph, root) = dfg_to_egraph(dfg);
	egraph.dot().to_svg("/tmp/initial.svg").unwrap();

	let runner = Runner::default().with_egraph(egraph).run(rules);
	let best = LpExtractor::new(&runner.egraph, AstSize).solve(root);

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
