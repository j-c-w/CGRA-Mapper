use EggLib::{load_ruleset, cost::BanCost};
use egg::*;

type EGraph = egg::EGraph<SymbolLang, ()>;

fn optimize(egraph: EGraph, mut roots: Vec<Id>) {
	let rules = load_ruleset("int");

	let runner =
		Runner::default()
			.with_iter_limit(3)
			.with_node_limit(100_000)
			.with_time_limit(std::time::Duration::from_secs(10))
			.with_egraph(egraph)
			// .with_explanations_enabled()
			.with_scheduler(SimpleScheduler)
      .run(&rules);
  runner.print_report();

  for r in &mut roots[..] {
      *r = runner.egraph.find(*r);
  }

  // FIXME: changing this JSON changes benchmark result
  let cost = BanCost::from_operations_file("../test/param.json");
  EggLib::serialize::to_file(&runner.egraph, &roots[..], cost.clone(), "/tmp/example2.json");

  /* {
    let start = std::time::Instant::now();
    let (c, e, r) = DagExtractor::new(&runner.egraph, cost.clone()).find_best(&roots[..]);
    println!("dag extraction time: {:?}", start.elapsed());
    println!("dag cost: {}", c);
    assert_eq!(c, egg::Graph::from_dfg(&e, r).cost(&cost));
  } */
  if !EggLib::USE_LPEXTRACTOR2 {
    // BROKEN BY INFINITY
    let start = std::time::Instant::now();
    let (e, r) = LpExtractor::new(&runner.egraph, cost.clone())
      .timeout(10.0)
      .solve_multiple(&roots[..]);
    println!("lp extraction time: {:?}", start.elapsed());
    println!("lp cost: {}", egg::Graph::from_dfg(&e, r).cost(&cost));
  }
  {
    let start = std::time::Instant::now();
    let (e, r) = LpExtractor2::new(&runner.egraph, cost.clone())
      .timeout(10.0)
      .solve_multiple(&roots[..]);
    println!("lp extraction time (2): {:?}", start.elapsed());
    println!("lp cost (2): {}", egg::Graph::from_dfg(&e, r).cost(&cost));
  }
}

fn main() {
  // TODO: use serialization instead
  let mut egraph = EGraph::default();
  let const_0 = egraph.add(SymbolLang::leaf("const_0"));
  let const_1 = egraph.add(SymbolLang::leaf("const_1"));
  let constant = egraph.add(SymbolLang::leaf("Constant"));
  let load = egraph.add(SymbolLang::leaf("load"));
  let sub = egraph.add(SymbolLang::new("sub", vec![load, const_1]));
  let add = egraph.add(SymbolLang::new("add", vec![load, const_1]));
  let load_constant = egraph.add(SymbolLang::new("load", vec![constant]));
  let getelementptr_load = egraph.add(SymbolLang::new("getelementptr", vec![constant, const_0, load]));
  let getelementptr_sub = egraph.add(SymbolLang::new("getelementptr", vec![constant, const_0, sub]));
  let store_add = egraph.add(SymbolLang::new("store", vec![add]));
  let icmp = egraph.add(SymbolLang::new("icmp", vec![load, load_constant]));
  let dummy_source = egraph.add(SymbolLang::leaf("DummySource35"));
  let load_g_load = egraph.add(SymbolLang::new("load", vec![getelementptr_load]));
  let load_g_sub = egraph.add(SymbolLang::new("load", vec![getelementptr_sub]));
  let dummy_target = egraph.add(SymbolLang::new("DummyTarget35", vec![icmp]));
  let br = egraph.add(SymbolLang::new("br", vec![icmp, dummy_source]));
  let fsub = egraph.add(SymbolLang::new("fsub", vec![load_g_load, load_g_sub]));
  let fmul = egraph.add(SymbolLang::new("fmul", vec![load_g_load, fsub]));
  let store_fmul = egraph.add(SymbolLang::new("store", vec![fmul, getelementptr_load]));
  let br_alone = egraph.add(SymbolLang::leaf("br"));
  
  let roots = vec![store_fmul, store_add, dummy_target, br, br_alone];
  egraph.dot().to_svg("/tmp/example.svg").unwrap();
  EggLib::serialize::to_file(&egraph, &roots[..], AstSize, "/tmp/example.json");

  optimize(egraph, roots);
}