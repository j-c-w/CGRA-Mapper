use EggLib::{/*load_ruleset, */cost::BanCost};
use egg::*;
use std::collections::{HashSet, HashMap};

type EGraph = egg::EGraph<SymbolLang, ()>;
type Rewrite = egg::Rewrite<SymbolLang, ()>;

fn main() {
  /*
  let ruleset_name = "int";
  let operations_file_path = "../test/param.json";

	let rules = load_ruleset(ruleset_name);
  let cost = BanCost::from_operations_file(operations_file_path);
  */
  let rules = vec![
		rewrite!("sub-to-add-neg"; "(sub ?x ?y)" => "(add ?x (neg ?y))"),
    rewrite!("neg-to-mul"; "(neg ?y)" => "(mul const_-1 ?y)"),
  ];
  let cost = BanCost::from_available(vec![
    "add", "mul", "const_-1",
    "v0", "v1", "v2", "v3", "v4",
  ]);

  let mut egraph = EGraph::default();

  // 1. add all RHS terms to the e-graph
  let init_start = std::time::Instant::now();
  let rhs_vec: Vec<Id> = rules.iter().map(|r| {
    let rhs_pat = r.applier.get_pattern_ast().unwrap();
    egraph.add_expr(&pattern_to_recexpr(rhs_pat))
  }).collect();
  println!("init time: {:?}", init_start.elapsed());

  egraph.dot().to_svg("/tmp/initial.svg").unwrap();

  // 2. rewrite RHS terms
	let runner = Runner::default()
    .with_iter_limit(10)
    .with_node_limit(1_000_000)
    .with_time_limit(std::time::Duration::from_secs(60))
    .with_egraph(egraph)
    // .with_explanations_enabled()
    .with_scheduler(SimpleScheduler)
    .run(&rules);
  runner.print_report();

  runner.egraph.dot().to_svg("/tmp/final.svg").unwrap();

  // 3. extract best RHS terms and build optimized ruleset
  let extraction_start = std::time::Instant::now();
  let rules_opt: Vec<_> = rules.iter().zip(rhs_vec.iter()).map(|(r, &rhs_id)| {
    LpExtractor2::new(&runner.egraph, cost.clone())
      .timeout(10.0)
      .solve(runner.egraph.find(rhs_id))
      .map(|rhs_opt| {
        // println!("lp cost (2): {}", egg::Graph::from_dfg(&e, r).cost(&cost));
        let lhs_pat = r.searcher.get_pattern().unwrap();
        let rhs_pat = r.applier.get_pattern_ast().unwrap();
        let rhs_opt_pat = recexpr_to_pattern(rhs_pat, &rhs_opt);
        Rewrite::new(r.name, lhs_pat.clone(), Pattern::new(rhs_opt_pat))
      })
  }).collect();
  println!("extraction time: {:?}", extraction_start.elapsed());

  println!("---- Optimized Rules ----");
  for (r, r_opt) in rules.iter().zip(rules_opt.iter()) {
    println!("{:?}", r);
    match r_opt {
      Some(r_opt) => println!("{:?}", r_opt),
      None => println!("[removed from ruleset]"),
    }
    
    println!("----");
  }
}

fn pattern_to_recexpr(p: &PatternAst<SymbolLang>) -> RecExpr<SymbolLang> {
  let mut e = RecExpr::default();
  let mut var_to_symbol = HashMap::<Var, Symbol>::new();

  for n_or_v in p.as_ref() {
    e.add(match n_or_v {
      ENodeOrVar::ENode(n) => n.clone(),
      ENodeOrVar::Var(v) => {
        let i = var_to_symbol.len();
        SymbolLang::leaf(*var_to_symbol.entry(*v).or_insert_with(|| {
          format!("v{}", i).parse().unwrap()
        }))
      }
    });
  }

  e
}

fn recexpr_to_pattern(reference: &PatternAst<SymbolLang>, r: &RecExpr<SymbolLang>) -> PatternAst<SymbolLang> {
  let mut p = PatternAst::default();
  let mut vars = HashSet::new();
  let mut symbol_to_var = HashMap::<Symbol, Var>::new();

  for n_or_v in reference.as_ref() {
    if let &ENodeOrVar::Var(v) = n_or_v {
      let i = vars.len();
      if vars.insert(v) {
        symbol_to_var.insert(
          format!("v{}", i).parse().unwrap(), v
        );
      }
    }
  }

  for n in r.as_ref() {
    p.add(
      match symbol_to_var.get(&n.op) {
        Some(v) => ENodeOrVar::Var(*v),
        None => ENodeOrVar::ENode(n.clone())
      }
    );
  }

  p
}