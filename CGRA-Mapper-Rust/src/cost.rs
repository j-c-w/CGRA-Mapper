use std::collections::{HashSet, HashMap};
use egg::*;

// This thing loads the operations in from a JSON file,
// returning all the available operations.
// i.e. the things that rewriting should target.
fn get_available_operations(path: &str) -> HashSet<String> {
    use std::fs::File;
    use std::io::Read;
    use tinyjson::*;

	let mut file = File::open(path).unwrap();
	let mut data = String::new();
	file.read_to_string(&mut data).unwrap();
	let json: JsonValue = data.parse().unwrap();
	let mut operations: HashSet<String> = HashSet::new();
	// println!("Parsed: {:?}", json);

    // Several operations are 'always avaiable' because
    // they are just implicit LLVM information
    // (or just proxies for load/store --- ideally the procies
    // for load/store will be fixed elsewhere).
    operations.insert("getelementptr".to_string());
    operations.insert("insertelement".into());
    operations.insert("extractelement".into());
    operations.insert("ret".into());
    operations.insert("phi".into());
    operations.insert("bitcast".into());
    operations.insert("trunc".into());

    // CGRA mapper sometimes produces loops w/out these.
    // I don't understand why that could be, because ISTM
    // like literally every loop ever needs to have both
    // of these to be useful, so give these a free pass
    // in the rewriter.
    operations.insert("load".into());
    operations.insert("store".into());


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
                operations.insert(op);
            }
        }
    }

	operations
}

pub(crate) struct BanCost {
    // could also have cost: HashMap<Symbol, f64>
    available: HashSet<Symbol>
}

impl BanCost {
    pub(crate) fn from_operations_file<P>(path: P) -> Self
        where P: AsRef<str>
    {
        let operations = get_available_operations(path.as_ref());
        println!("supported operations are {:?}", operations);
        BanCost::from_available(operations)
    }

    pub(crate) fn from_available<I>(available: I) -> Self
        where I: IntoIterator, I::Item: AsRef<str>
    {
        BanCost {
            available: available.into_iter().map(|s| Symbol::from(s.as_ref())).collect::<HashSet<_>>(),
        }
    }
}

impl LpCostFunction<SymbolLang, ()> for BanCost {
    fn node_cost(&mut self, _egraph: &EGraph<SymbolLang, ()>, _eclass: Id, enode: &SymbolLang) -> f64 {
        if self.available.contains(&enode.op) {
            1.0
        } else {
            1_000_000.0 // does not seem to like f64::INFINITY
        }
    }
}
