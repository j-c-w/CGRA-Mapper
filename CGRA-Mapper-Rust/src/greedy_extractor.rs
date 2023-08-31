use crate::*;
use std::cmp::Ordering;
use std::fmt::Debug;

pub fn find_bests<CF>(
  egraph: &EGraph<SymbolLang, ()>,
  mut cost_f: CF,
  roots: &[Id],
) -> (RecExpr<SymbolLang>, Vec<Id>)
where
  CF: CostFunction<SymbolLang>,
  CF::Cost: 'static,
{
  assert!(egraph.clean);
  
  let mut extracted = HashMap::default();
  let analysis = ExtractAnalysis {
    cost_f: &mut cost_f,
  };
  one_shot_analysis(&egraph, analysis, &mut extracted);

  // let cost = roots.map(|r| extracted[egraph.find(r)].0).sum();

  let mut expr = RecExpr::default();
  let mut g_to_e = HashMap::<Id, Id>::default();
  let mut todo = Vec::from(roots);

  while let Some(id) = todo.last().copied() {
    assert!(id == egraph.find(id));

    if g_to_e.contains_key(&id) {
      todo.pop();
      continue;
    }

    let node = extracted[&id].1.clone();

    let mut all_children_done = true;
    for child in node.children() {
      if !g_to_e.contains_key(child) {
        all_children_done = false;
        todo.push(*child);
      }
    }

    if all_children_done {
      let node = node.map_children(|id| g_to_e[&id]);
      let expr_id = expr.add(node);
      g_to_e.insert(id, expr_id);
      todo.pop();
    }
  }

  let mut expr_roots = roots.iter().map(|id| g_to_e[&id]).collect();
  (expr, expr_roots)
}

pub struct ExtractAnalysis<'a, CF> {
  cost_f: &'a mut CF,
}

impl<'a, L, A, CF> SemiLatticeAnalysis<L, A> for ExtractAnalysis<'a, CF>
where
  L: Language + 'static,
  A: Analysis<L>,
  CF: CostFunction<L>,
  CF::Cost: 'static,
{
  type Data = (CF::Cost, L);

  fn make<'b>(
    &mut self,
    _egraph: &EGraph<L, A>,
    enode: &L,
    analysis_of: &'b impl Fn(Id) -> &'b Self::Data,
  ) -> Self::Data
  where Self::Data: 'b,
  {
    (self.cost_f.cost(enode, |c| (*analysis_of)(c).0.clone()), enode.clone())
  }

  fn merge(&mut self, a: &mut Self::Data, b: Self::Data) -> DidMerge {
    if a.0 < b.0 {
      DidMerge(false, true)
    } else if a.0 == b.0 {
      DidMerge(false, false)
    } else {
      *a = b;
      DidMerge(true, false)
    }
  }
}

pub trait SemiLatticeAnalysis<L: Language, A: Analysis<L>> {
    type Data: Debug + 'static;

    fn make<'b>(
        &mut self,
        egraph: &EGraph<L, A>,
        enode: &L,
        analysis_of: &'b impl Fn(Id) -> &'b Self::Data,
    ) -> Self::Data
    where
        Self::Data: 'b;
    fn merge(&mut self, a: &mut Self::Data, b: Self::Data) -> DidMerge;
}

pub fn one_shot_analysis<L: Language, A: Analysis<L>, B: SemiLatticeAnalysis<L, A>>(
    egraph: &EGraph<L, A>,
    mut analysis: B,
    data: &mut HashMap<Id, B::Data>,
) {
    assert!(egraph.clean);

    let mut analysis_pending = HashSetQueuePop::<(L, Id)>::new();
    // works with queue but IndexSet is stack
    // IndexSet::<(L, Id)>::default();

    for eclass in egraph.classes() {
        for enode in &eclass.nodes {
            if enode.all(|c| data.contains_key(&egraph.find(c))) {
                assert!(enode.all(|c| egraph.find(c) == c));
                assert!(egraph.find(eclass.id) == eclass.id);
                analysis_pending.insert((enode.clone(), eclass.id));
            }
        }
    }

    resolve_pending_analysis(egraph, &mut analysis, data, &mut analysis_pending);

    debug_assert!(egraph.classes().all(|eclass| data.contains_key(&eclass.id)));
}

fn resolve_pending_analysis<L: Language, A: Analysis<L>, B: SemiLatticeAnalysis<L, A>>(
    egraph: &EGraph<L, A>,
    analysis: &mut B,
    data: &mut HashMap<Id, B::Data>,
    analysis_pending: &mut HashSetQueuePop<(L, Id)>,
) {
    while let Some((node, id)) = analysis_pending.pop() {
        assert!(node.all(|c| egraph.find(c) == c));
        assert!(egraph.find(id) == id);

        if node.all(|id| data.contains_key(&id)) {
            let eclass = &egraph[id];
            let node_data = analysis.make(egraph, &node, &|id| &data[&id]);
            let mut pending_parents = |eclass: &EClass<L, _>| {
              analysis_pending.extend(eclass.parents().map(|(n, id)|
               (n.clone().map_children(|c| egraph.find(c)),
                egraph.find(id))));
            };
            let new_data = match data.remove(&id) {
                None => {
                    pending_parents(eclass);
                    node_data
                }
                Some(mut existing) => {
                    let DidMerge(may_not_be_existing, _) = analysis.merge(&mut existing, node_data);
                    if may_not_be_existing {
                        pending_parents(eclass);
                    }
                    existing
                }
            };
            data.insert(id, new_data);
        } else {
            analysis_pending.insert((node, id));
        }
    }
}

pub struct HashSetQueuePop<T> {
    map: HashSet<T>,
    queue: std::collections::VecDeque<T>,
}

impl<T: Eq + std::hash::Hash + Clone> HashSetQueuePop<T> {
    pub fn new() -> Self {
        HashSetQueuePop {
            map: HashSet::default(),
            queue: std::collections::VecDeque::new(),
        }
    }

    pub fn insert(&mut self, t: T) {
        if self.map.insert(t.clone()) {
            self.queue.push_back(t);
        }
    }

    pub fn extend<I>(&mut self, iter: I)
    where
        I: IntoIterator<Item = T>,
    {
        for t in iter.into_iter() {
            self.insert(t);
        }
    }

    pub fn pop(&mut self) -> Option<T> {
        let res = self.queue.pop_front();
        res.as_ref().map(|t| self.map.remove(t));
        res
    }
}

impl<L: Language, A: Analysis<L>> SemiLatticeAnalysis<L, A> for AstSize {
    type Data = usize;

    fn make<'a>(
        &mut self,
        _egraph: &EGraph<L, A>,
        enode: &L,
        analysis_of: &'a impl Fn(Id) -> &'a Self::Data,
    ) -> Self::Data
    where
        Self::Data: 'a,
    {
        enode.fold(1usize, |size, id| size + analysis_of(id))
    }

    fn merge(&mut self, a: &mut Self::Data, b: Self::Data) -> DidMerge {
        match (*a).cmp(&b) {
            Ordering::Less => DidMerge(false, true),
            Ordering::Equal => DidMerge(false, false),
            Ordering::Greater => {
                *a = b;
                DidMerge(true, false)
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::*;

    #[test]
    fn simple_analysis() {
        let mut egraph = EGraph::<SymbolLang, ()>::default();
        let a = egraph.add(SymbolLang::leaf("a"));
        let z = egraph.add(SymbolLang::leaf("0"));
        let apz = egraph.add(SymbolLang::new("+", vec![a, z]));

        egraph.union(a, apz);
        egraph.rebuild();

        let mut data = HashMap::default();
        one_shot_analysis(&egraph, AstSize, &mut data);

        assert_eq!(data[&egraph.find(apz)], 1);
    }
}
