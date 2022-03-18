use egg::*;
use std::os::raw::c_char;
use std::mem::size_of;

#[repr(C)]
pub struct CppNode {
	op: *const c_char,

	num_children: u16,
	child_ids: *const u32
}

type CppDFG = *const CppNode;

fn dfg_to_egraph(input: CppDFG, len: u32) -> (EGraph<SymbolLang, ()>, Id) {
	assert!(input != std::ptr::null());
	let nodes = unsafe { std::slice::from_raw_parts(input, len as usize) };
	let mut egraph: EGraph<SymbolLang, ()> = Default::default();
	let mut eclasses = vec![];
	for node in nodes {
		let op = Symbol::from(unsafe { std::ffi::CStr::from_ptr(node.op) }.to_str().unwrap());
		let children = unsafe { std::slice::from_raw_parts(node.child_ids, node.num_children as usize) }.iter()
			.map(|&c| eclasses[c as usize]).collect::<Vec<_>>();
		eclasses.push(egraph.add(SymbolLang::new(op, children)));
	}

	let root = *eclasses.last().unwrap(); // root is last node in array?
	(egraph, root)
}

fn expr_to_dfg(expr: RecExpr<SymbolLang>) -> CppDFG {
	let enodes = expr.as_ref();
	let dfg = unsafe { libc::malloc(enodes.len() * size_of::<CppNode>()) } as *mut CppNode;
	let nodes = unsafe { std::slice::from_raw_parts_mut(dfg, enodes.len()) };
	for (en, n) in enodes.iter().zip(nodes.iter_mut()) {
		n.op = std::ffi::CString::new(en.op.as_str()).unwrap().into_raw();
		let child_ids = unsafe { libc::malloc(en.children.len() * size_of::<u32>()) } as *mut u32;
		for (child_id, &c) in unsafe { std::slice::from_raw_parts_mut(child_ids, en.children.len()) }.iter_mut().zip(en.children.iter()) {
			*child_id = usize::from(c).try_into().unwrap();
		}
		n.num_children = en.children.len().try_into().unwrap();
		n.child_ids = child_ids;
	}
	dfg
}

#[no_mangle]
pub extern "C" fn optimize_with_egraphs(input: CppDFG, len: u32) -> *const CppDFG {
	let rules: &[Rewrite<SymbolLang, ()>] = &[
		rewrite!("sub-to-add-neg"; "(sub ?x ?y)" => "(add ?x (neg ?y))"),

		rewrite!("commute-add"; "(add ?x ?y)" => "(add ?y ?x)"),
		rewrite!("commute-mul"; "(mul ?x ?y)" => "(mul ?y ?x)"),

		rewrite!("add-0"; "(add ?x 0)" => "?x"),
		rewrite!("mul-0"; "(mul ?x 0)" => "0"),
		rewrite!("mul-1"; "(mul ?x 1)" => "?x"),
	];

	let (egraph, root) = dfg_to_egraph(input, len);
	egraph.dot().to_svg("/tmp/initial.svg").unwrap();

	let runner = Runner::default().with_egraph(egraph).run(rules);
	let best = LpExtractor::new(&runner.egraph, AstSize).solve(root);

	{
		let mut g: EGraph<SymbolLang, ()> = Default::default();
		g.add_expr(best);
		g.dot().to_svg("/tmp/final.svg").unwrap();
	}

	let ptr = unsafe { libc::malloc(size_of::<CppDFG>()) } as *mut CppDFG;
	assert!(ptr != std::ptr::null_mut());
	unsafe { *ptr = expr_to_dfg(best) };
	
	ptr
}
