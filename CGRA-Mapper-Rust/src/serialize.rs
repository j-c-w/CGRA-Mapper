// use std::collections::HashMap;
use std::fmt::Display;
use egg::*;

pub fn to_file<L, A, CF>(
    egraph: &EGraph<L, A>,
    roots: &[Id],
    mut cost_function: CF,
    path: impl AsRef<std::path::Path>,
)
where
    L: Language + Display,
    A: Analysis<L>,
    CF: LpCostFunction<L, A>
{
    let seg = egg_to_serialized_egraph(egraph, roots, cost_function);
    seg.to_json_file(path).unwrap();
}

fn egg_to_serialized_egraph<L, A, CF>(
    egraph: &EGraph<L, A>,
    roots: &[Id],
    mut cost_function: CF
) -> egraph_serialize::EGraph
where
    L: Language + Display,
    A: Analysis<L>,
    CF: LpCostFunction<L, A>
{
    use egraph_serialize::*;
    let mut out = EGraph::default();

    for class in egraph.classes() {
        for (i, node) in class.nodes.iter().enumerate() {
            out.add_node(
                format!("{}.{}", class.id, i),
                Node {
                    op: node.to_string(),
                    children: node
                        .children()
                        .iter()
                        .map(|id| NodeId::from(format!("{}.0", id)))
                        .collect(),
                    eclass: ClassId::from(format!("{}", class.id)),
                    cost: Cost::new(cost_function.node_cost(egraph, class.id, node)).unwrap(),
                },
            )
        }
    }

    out.root_eclasses.extend(roots.iter().map(|id| ClassId::from(format!("{}", id))));

    out
}
/*
pub fn egg_of_serialized_egraph(egraph: &egraph_serialize::EGraph) -> (EGraph<SymbolLang, ()>, Vec<Id>) {
    // use egraph_serialize::*;
    let mut out = EGraph<SymbolLang, ()>::default();
    let mut classes = HashMap::new(); // ser nid -> egg cid
    for (cid, class) in egraph.classes() {
      for nid in &class.nodes {

      }
    }
    for class in egraph.classes() {
        for (i, node) in class.nodes.iter().enumerate() {
            out.add_node(
                format!("{}.{}", class.id, i),
                Node {
                    op: node.to_string(),
                    children: node
                        .children()
                        .iter()
                        .map(|id| NodeId::from(format!("{}.0", id)))
                        .collect(),
                    eclass: ClassId::from(format!("{}", class.id)),
                    // cost: Cost::new(1.0).unwrap(),
                },
            )
        }
    }
    out
}

fn egg_of_serialized_egraph_visit_node(
  egraph: &egraph_serialize::EGraph,
  classes: &mut HashMap<egraph_serialize::NodeId, Id>,
  out: &mut EGraph<SymbolLang, ()>,
  nid: egraph_serialize::NodeId,
) -> Id {
  let node = &egraph[nid];
  let op = Symbol::from(node.op);
  for &nidc in &node.children {
    egg_of_serialized_egraph_visit_node()
  }

}
*/