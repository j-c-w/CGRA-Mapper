use std::collections::{HashSet, HashMap};
use egg::*;
use crate::USE_LPEXTRACTOR2;

// DagCostFunction<SymbolLang>
pub trait MultiCostFunction: LpCostFunction<SymbolLang, ()> +  GraphCostFunction<SymbolLang> {}

pub trait Coster {
    fn cost(&self, g: &Graph<SymbolLang>) -> f64;
    fn pattern_cost(&self, ast: &PatternAst<SymbolLang>) -> f64;
}

impl LpCostFunction<SymbolLang, ()> for Box<dyn MultiCostFunction> {
    fn node_cost(&mut self, egraph: &EGraph<SymbolLang, ()>, eclass: Id, enode: &SymbolLang) -> f64 {
        LpCostFunction::node_cost(self.as_mut(), egraph, eclass, enode)
    }
}

impl GraphCostFunction<SymbolLang> for Box<dyn MultiCostFunction> {
    fn node_cost(&mut self, enode: &SymbolLang) -> f64 {
        GraphCostFunction::node_cost(self.as_mut(), enode)
    }
}

fn operations_in_pattern(ast: &PatternAst<SymbolLang>) -> Vec<String> {
    // Get the enodes in the pattern.
    let mut nodes = vec![];
    for n in ast.as_ref() {
        if let ENodeOrVar::ENode(v) = n {
            // double-count operations
            nodes.push(String::from(v.to_string()));
        }
    }

    nodes
}

// This thing loads the operations in from a JSON file,
// returning all the available operations and their count.
// i.e. the things that rewriting should target.
fn get_available_operations(path: &str) -> HashMap<String, Option<u16>> {
    use std::fs::File;
    use std::io::Read;
    use tinyjson::*;

	let mut file = File::open(path).unwrap();
	let mut data = String::new();
	file.read_to_string(&mut data).unwrap();
	let json: JsonValue = data.parse().unwrap();
	let mut operations: HashMap<String, Option<u16>> = HashMap::new();
	// println!("Parsed: {:?}", json);

    // Several operations are 'always avaiable' because
    // they are just implicit LLVM information
    // (or just proxies for load/store --- ideally the procies
    // for load/store will be fixed elsewhere).
    operations.insert("getelementptr".to_string(), None);
    operations.insert("shufflevector".into(), None);
    operations.insert("insertelement".into(), None);
    operations.insert("extractelement".into(), None);
    operations.insert("ret".into(), None);
    operations.insert("phi".into(), None);
    operations.insert("bitcast".into(), None);
    operations.insert("trunc".into(), None);
	operations.insert("fptosi".into(), None);
	operations.insert("sitofp".into(), None);
    operations.insert("select".into(), None);

    // Various constants: we don't do a super efficient
    // job of managing these, but do assume that they can be
    // programmed into any PE in teh compiler.
    operations.insert("const_-1".into(), None);
    operations.insert("Constant".into(), None);
	operations.insert("const_fp".into(), None);
    operations.insert("const_2".into(), None);
    operations.insert("const_32".into(), None);
    operations.insert("const_1".into(), None);
    operations.insert("const_0".into(), None);
    operations.insert("const_something".into(), None);
    operations.insert("const_31".into(), None);
    operations.insert("const_2pow32".into(), None);


    // CGRA mapper sometimes produces loops w/out these.
    // I don't understand why that could be, because ISTM
    // like literally every loop ever needs to have both
    // of these to be useful, so give these a free pass
    // in the rewriter.
    operations.insert("load".into(), None);
    operations.insert("store".into(), None);


/*
    fn unwrap_object(v: &JsonValue, loc: &str) -> &HashMap<String, JsonValue> {
        match v {
            Object(o) => o,
            _ => panic!("expected JSON object for {}", loc)
        }
    }
*/
	// The json is a 2d map of col number, row number
	// and then a list of the operations it supports.
    let mut root: HashMap<_, _> = json
        .try_into().expect("expected JSON object at the root");
	let op_rows: HashMap<_, _> = root
        .remove("operations").expect("expected 'operations' key")
        .try_into().expect("expected JSON object as 'operations' value");
        
    for (_, row_values) in op_rows {
        let row: HashMap<_, _> = row_values
            .try_into().expect("expected JSON object as row value");
        for (_, col_values) in row {
            let col: Vec<_> = col_values
                .try_into().expect("expected JSON array as column value");
            for op_value in col {
                let op: String = op_value
                    .try_into().expect("expected JSON string as operator value");
                // println!("Operation {}", s);
                if let Some(value) = operations.entry(op).or_insert(Some(0)).as_mut() {
                    *value += 1;
                }
            }
        }
    }
    
	operations
}

#[derive(Clone)]
pub struct BanCost {
    // could also have cost: HashMap<Symbol, f64>
    available: HashSet<Symbol>
}

impl Coster for BanCost {
    fn cost(&self, g: &Graph<SymbolLang>) -> f64 {
        g.cost(self)
    }
    fn pattern_cost(&self, ast: &PatternAst<SymbolLang>) -> f64 {
        let ops = operations_in_pattern(ast);
        let mut sum = 0.0;
        for op in ops {
            sum += ban_cost(&self.available, &Symbol::from(&op), 10_000.0);
        }
        sum
    }
}

impl Coster for LookupCost {
    fn cost(&self, g: &Graph<SymbolLang>) -> f64 {
        g.cost(self)
    }
    fn pattern_cost(&self, ast: &PatternAst<SymbolLang>) -> f64 {
        let ops = operations_in_pattern(ast);
        let mut sum = 0.0;
        for op in ops {
            sum += lookup_cost(&self.costs, 10_000.0, &Symbol::from(&op));
        }
        sum
    }
}

impl BanCost {
    pub fn from_operations_file_and_list<P,I>(path: P, available: I) -> Self
        where P: AsRef<str>, I: IntoIterator<Item = std::string::String>, I::Item: AsRef<str>
    {
        let mut path_operations = get_available_operations(path.as_ref());
        for op in available {
            path_operations.insert(op, None);
        }

        BanCost::from_available(path_operations.keys())
    }
    pub fn from_operations_file<P>(path: P) -> Self
        where P: AsRef<str>
    {
        let operations = get_available_operations(path.as_ref());
        println!("supported operations are {:?}", operations);
        let ban_cost = BanCost::from_available(operations.keys());
        println!("Available ops are {:?}", ban_cost.available);
        ban_cost
    }

    pub fn from_available<I>(available: I) -> Self
        where I: IntoIterator, I::Item: AsRef<str>
    {
        BanCost {
            available: available.into_iter().map(|s| Symbol::from(s.as_ref())).collect::<HashSet<_>>(),
        }
    }
}

fn ban_cost(available: &HashSet<Symbol>, symbol: &Symbol, ban_value: f64) -> f64 {
    // println!("Looking up {}", symbol);
    if symbol.as_str().starts_with("Dummy") || symbol.as_str().starts_with("const") {
        // println!("Was a dummy node!");
        // The C part inserts dummy nodes to break cycles.
        0.0
    } else if available.contains(symbol) {
        // println!("Found find symbol");
        1.0
    } else {
        // println!("Didn't find symbol {}", symbol.as_str());
        ban_value
    }
}

impl DagCostFunction<SymbolLang> for BanCost {
    type Cost = f64;
    fn zero(&mut self) -> f64 { 0.0 }
    fn node_cost(&mut self, enode: &SymbolLang) -> f64 {
        let ban_value = 10_000.0;
        ban_cost(&self.available, &enode.op, ban_value)
    }
}

impl LpCostFunction<SymbolLang, ()> for BanCost {
    fn node_cost(&mut self, _egraph: &EGraph<SymbolLang, ()>, _eclass: Id, enode: &SymbolLang) -> f64 {
        let ban_value = if false { std::f64::INFINITY } else { 10_000.0 };
        ban_cost(&self.available, &enode.op, ban_value)
    }
}

impl GraphCostFunction<SymbolLang> for &BanCost {
    fn node_cost(&mut self, enode: &SymbolLang) -> f64 {
        let ban_value = 10_000.0;
        ban_cost(&self.available, &enode.op, ban_value)
    }
}

// TODO: to this for generic &T / T ?
impl GraphCostFunction<SymbolLang> for BanCost {
    fn node_cost(&mut self, enode: &SymbolLang) -> f64 {
        (self as &BanCost).node_cost(enode)
    }
}

// TODO: to this for generic &T / T ?
impl MultiCostFunction for BanCost {}

#[derive(Clone)]
pub(crate) struct LookupCost {
    costs: HashMap<Symbol, f64>,
}

impl LookupCost {
    pub(crate) fn from_operations_frequencies<P>(path: P) -> Self
        where P: AsRef<str>
    {
        let operations = get_available_operations(path.as_ref());
        println!("supported operations are {:?}", operations);

        let total_ops: f64 = operations.values().map(|c| c.unwrap_or(0) as f64).sum();
        let costs = operations.into_iter().map(|(s, c)| {
            let cost = (total_ops - (c.map(|n| n as f64).unwrap_or(total_ops - 1.0))) / total_ops;
            (Symbol::from(s), cost)
        }).collect::<HashMap<Symbol, f64>>();
        println!("costs are {:?}", costs);

        LookupCost { costs }
    }
}

fn lookup_cost(costs: &HashMap<Symbol, f64>, default: f64, symbol: &Symbol) -> f64 {
    if symbol.as_str().starts_with("Dummy") || symbol.as_str().starts_with("const") {
        0.0
    } else {
        costs.get(symbol).cloned().unwrap_or(default)
    }
}

impl DagCostFunction<SymbolLang> for LookupCost {
    type Cost = f64;
    fn zero(&mut self) -> f64 { 0.0 }
    fn node_cost(&mut self, enode: &SymbolLang) -> f64 {
        let default_cost = 1_000_000.0;
        lookup_cost(&self.costs, default_cost, &enode.op)
    }
}

impl LpCostFunction<SymbolLang, ()> for LookupCost {
    fn node_cost(&mut self, _egraph: &EGraph<SymbolLang, ()>, _eclass: Id, enode: &SymbolLang) -> f64 {
        let default_cost = if USE_LPEXTRACTOR2 { std::f64::INFINITY } else { 1_000_000.0 };
        lookup_cost(&self.costs, default_cost, &enode.op)
    }
}

impl GraphCostFunction<SymbolLang> for &LookupCost {
    fn node_cost(&mut self, enode: &SymbolLang) -> f64 {
        let default_cost = 1_000_000.0;
        lookup_cost(&self.costs, default_cost, &enode.op)
    }
}

// TODO: to this for generic &T / T ?
impl GraphCostFunction<SymbolLang> for LookupCost {
    fn node_cost(&mut self, enode: &SymbolLang) -> f64 {
        (self as &LookupCost).node_cost(enode)
    }
}

// TODO: to this for generic &T / T ?
impl MultiCostFunction for LookupCost {}
