use egg::*;
use std::os::raw::c_char;
use std::mem::size_of;
use cost::*;
use rules::*;

mod cost;
mod rules;

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

fn dfg_nodes(dfg: &CppDFG) -> &[CppNode] {
    unsafe { std::slice::from_raw_parts(dfg.nodes, dfg.count as usize) }
}

fn node_op(node: &CppNode) -> &str {
    unsafe { std::ffi::CStr::from_ptr(node.op) }.to_str().unwrap()
}

fn node_children(node: &CppNode) -> &[u32] {
    unsafe { std::slice::from_raw_parts(node.child_ids, node.num_children as usize) }
}

fn dfg_to_egraph(dfg: CppDFG) -> (EGraph<SymbolLang, ()>, Vec<Id>) {
    let nodes = dfg_nodes(&dfg);
	let mut egraph: EGraph<SymbolLang, ()> = Default::default();
	let mut eclasses = vec![];
    let mut is_root = (0..nodes.len()).map(|_| true).collect::<Vec<_>>(); // could use bit vector
	// DEBUG >>>
	// let test = 
	// unsafe { std::slice::from_raw_parts(std::ptr::null_mut(), 0) }.iter()
	//	.map(|&c: &u32| eclasses[c as usize]).collect::<Vec<_>>();
	// println!("{:?}", test);
	// <<<
	for node in nodes {
		let op = Symbol::from(node_op(node));
		// DEBUG
		println!("{}: {} with {} children", eclasses.len(), op, node.num_children);
		let children = node_children(node).iter()
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

fn dfg_to_graph(dfg: CppDFG) -> Graph<SymbolLang> {
    let nodes = dfg_nodes(&dfg);
	let mut graph: Graph<SymbolLang> = Default::default();
	let mut ids = Vec::with_capacity(nodes.len());
    let mut is_root = (0..nodes.len()).map(|_| true).collect::<Vec<_>>(); // could use bit vector
                                                                          //
	for node in nodes {
		let op = Symbol::from(node_op(node));
		// DEBUG
		println!("{}: {} with {} children", ids.len(), op, node.num_children);
		let children = node_children(node).iter()
			.map(|&c| {
				// DEBUG
				println!("access: {} / {}", c, ids.len());
                is_root[c as usize] = false;
				ids[c as usize]
			}).collect::<Vec<_>>();
		ids.push(graph.add(SymbolLang::new(op, children)));
	}

    let mut roots = ids.iter().cloned().zip(is_root.iter().cloned())
        .filter_map(|(e, is_r)| if is_r { println!("{:?}", graph[e]); Some(e) } else { None }).collect::<Vec<_>>();
    // we remove duplicates, why is this necessary?
    roots.sort();
    roots.dedup();

    for r in roots {
        graph.add_root(r);
    }

	graph
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

	let rules = rules();

	let (egraph, mut roots) = dfg_to_egraph(dfg);
    println!("identified {} roots", roots.len());
	// egraph.dot().to_svg("/tmp/initial.svg").unwrap();

	let runner = Runner::default().with_egraph(egraph).run(&rules);
    // runner.egraph.dot().to_svg("/tmp/egraph.svg").unwrap();

    for r in &mut roots[..] {
        *r = runner.egraph.find(*r);
    }
	// TODO --- json as an argument rather than a constant?
    let cost = BanCost::from_operations_file("param.json");
	let (best, _best_roots) = LpExtractor::new(&runner.egraph, cost).solve_multiple(&roots[..]);

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

#[no_mangle]
pub extern "C" fn optimize_with_graphs(dfg: CppDFG) -> CppDFGs {
    println!("entering Rust, using standard rewriting");

	let rules = rules();
    let mut graph = dfg_to_graph(dfg);
    // TODO:
    // println!("identified {} roots", graph.roots.len());
	graph.to_svg("/tmp/initial.svg").unwrap();

    let mut normalized = false;
    let mut applied = Vec::new();
    while !normalized {
        normalized = true;

        for r in &rules {
            // TODO: avoid recompiling Pattern here
            let lhs = Pattern::from(r.searcher.get_pattern_ast().unwrap().clone());
            let rhs = r.applier.get_pattern_ast().unwrap();

            // TODO: replace pattern size with proper cost
            if lhs.ast.as_ref().len() <= rhs.as_ref().len() {
                break;
            }

            while let Some((id, subst)) = lhs.search_graph(&graph) {
                graph.replace(id, &rhs, &subst);
                applied.push(r.name);
                normalized = false;
            }
        }
    }

	graph.to_svg("/tmp/final.svg").unwrap();
    println!("applied rules: {:?}", applied);

    let best = graph.as_dfg();

	let dfgs_ptr = unsafe { libc::malloc(size_of::<CppDFG>()) } as *mut CppDFG;
	assert!(dfgs_ptr != std::ptr::null_mut());
	unsafe { *dfgs_ptr = expr_to_dfg(best) };
	
	CppDFGs { dfgs: dfgs_ptr, count: 1 }
}
