use EggLib::{load_rulesets_from_names, cost::BanCost};
use egg::*;
use std::collections::{HashSet, HashMap};
use clap::{Arg,App,Values};
use serde_json::{Map,Value};
use std::sync::Arc;

type EGraph = egg::EGraph<SymbolLang, ()>;
type Rewrite = egg::Rewrite<SymbolLang, ()>;

fn main() {
  let ruleset_name = "int";
  let operations_file_path = "../test/param.json";

  let args = App::new("RewriteRuleGenerator")
      .version("1.0")
      .about("Generate static rules")
      .arg(
          Arg::with_name("operations_file")
          .help("CGRA description file")
          .required(true)
          .index(1)
      )
      .arg(
          Arg::with_name("output_file")
          .help("Output file")
          .required(true)
          .index(2)
      )
      // take any number of --rulset <arg> where
      // arg can be [int, fp, stochastic, boolean]
      .arg(
          Arg::with_name("ruleset")
          .help("Ruleset type")
          .required(false)
          .multiple(true)
          .takes_value(true)
          .long("ruleset")
      )
      .get_matches();

  let operations_file = args.value_of("operations_file").unwrap();
  let output_file = args.value_of("output_file").unwrap();
  let rulesets: Vec<&str> = args.values_of("ruleset").map(|x| x.collect()).unwrap_or(vec![]);

  let rules = load_rulesets_from_names(rulesets.iter().map(|&x| x.into()).collect());
  let variable_ops: Vec<String> = vec!["v0".to_string(), "v1".to_string(), "v2".to_string(),
  "v3".to_string(), "v4".to_string(), "v5".to_string(), "v6".to_string(), "v7".to_string(),
  "v8".to_string(), "v9".to_string(),
  "v10".to_string()];
  let cost = BanCost::from_operations_file_and_list(operations_file_path, variable_ops);
  /*
  let rules = vec![
		rewrite!("sub-to-add-neg"; "(add ?x (neg ?y))" => "(sub ?x ?y)"),
  ];
  let rules = vec![
		rewrite!("sub-to-add-neg"; "(sub ?x ?y)" => "(add ?x (neg ?y))"),
    rewrite!("neg-to-mul"; "(neg ?y)" => "(mul const_-1 ?y)"),
    rewrite!("useless-rule"; "(plop ?y)" => "(plip ?y)"),
  ];
  let cost = BanCost::from_available(vec![
    "sub", "mul", "const_-1",
    "v0", "v1", "v2", "v3", "v4",
  ]);
  */

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
        Rewrite::new(r.name, lhs_pat.clone(), Pattern::new(rhs_opt_pat)).unwrap()
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

  // construct a json like { "operations": [ { "name": ..., "searcher": ..., "applier": ...}, .. ] }
 let mut operations = Vec::new();
  for r in rules_opt.iter() {
    match r {
      Some(r) => {
        let mut operation = Map::new();
        operation.insert("name".into(), Value::String(r.name.clone().to_string()));
        operation.insert("searcher".into(), Value::String(Arc::clone(&r.searcher).get_pattern_ast().unwrap().to_string()));
        operation.insert("applier".into(), Value::String(r.applier.get_pattern_ast().unwrap().clone().to_string()));
        operations.push(Value::Object(operation));
      },
      None => {},
    }
  }

  let mut json = HashMap::new();
  json.insert("operations", Value::Array(operations));

  println!("---- JSON ----");
  println!("{}", serde_json::to_string_pretty(&json).unwrap());
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
