use egg::*;

pub(crate) fn rules() -> Vec<Rewrite<SymbolLang, ()>> {
    vec![
		// Rules we came up with:
		rewrite!("sub-to-add-neg"; "(sub ?x ?y)" => "(add ?x (mul const_-1 ?y))"),
        rewrite!("add-to-sub-neg"; "(add ?x ?y)" => "(sub ?x (mul const_-1 ?y))"),
        rewrite!("mul-to-neg"; "(mul const_-1 ?y)" => "(neg ?y)"),
        rewrite!("lsh-to-lshr-mul"; "(lsh ?x ?y)" => "(mul ?x (lshr const_IntMax (sub const_32 ?y)))"),
        rewrite!("lsh-to-ashr-mul"; "(lsh ?x ?y)" => "(mul ?x (ashr const_IntMax (sub const_32 ?y)))"),

        // Add into the highest bit leaves you with the equivalent
        // of a negation :)
        rewrite!("neg-to-add"; "(neg ?x)" => "(add const_2pow32 ?x)"),

		// TODO -- make sure these only apply to things treated
		// as booleans.
		rewrite!("and-to-mul"; "(and ?x ?y)" => "(mul ?x ?y)"),
		rewrite!("or-to-add"; "(or ?x ?y)" => "(add ?x ?y)"),
        rewrite!("xor-to-or-and"; "(xor ?x ?y)" => "(sub (or ?x ?y) (and ?x ?y))"),// actually I think this one is generic.
        

        // Rewrite logic ops into icmp --- also should be only
        // boolean logic ops here.
        // I checked this one, it's the only non-trivial one in
        // this group of rules :)
        // The reason it's so complicated is because it tries
        // to support non-1 ?x/?y that are true
        rewrite!("xor-to-icmp"; "(xor ?x ?y)" => "(icmp (icmp ?x 0) (icmp (not $y) 1))"),
        rewrite!("not-to-icmp"; "(not ?x)" => "(icmp ?x 0)"),
        rewrite!("and-to-or"; "(and ?x ?y)" => "(not (or (not ?x) (not ?y)))"),
        rewrite!("or-to-and"; "(or ?x ?y)" => "(not (and (not ?x) (not ?y)))"),

        // FP rule  we came up with:
        // Not intended to be correct: require -funsafe-math-operations or similar.
        // Apply a similar threshold to GCC for 'correctness' here.
        rewrite!("fp-sub-to-add-neg"; "(fsub ?x ?y)" => "(fadd ?x (fmul const_-1 ?y))"),
        rewrite!("fp-add-to-sub"; "(fadd ?x ?y)" => "(fsub ?x (fmul const_-1 ?y))"),
        rewrite!("fp-add-to-neg"; "(fadd ?x ?y)" => "(fsub ?x (fneg ?y))"),
        rewrite!("fp-mul-to-neg"; "(fmul const_-1 ?y)" => "(fneg ?y)"),
        // I think this might even infringe GCC's limits for ffast-math...
        rewrite!("fp-mul-to-div"; "(fmul ?x ?y)" => "(fdiv ?x (fdiv 1 ?y))"),

        // Integer add into the correct spot in FP gives you
        // equivalent of negation
        // Note that this only applies for IEEE format (or other
        // formats where the sign bit is the top one
        // and can overflow)
        rewrite!("fp-fneg-to-add"; "(fneg ?x)" => "(add const_2pow32 ?x)"),



		// Rules from GCC (these are from :
		// https://github.com/gcc-mirror/gcc/blob/master/gcc/match.pd commit https://github.com/gcc-mirror/gcc/blob/7690bee9f36ee02b7ad0b8a7e7a3e08357890dc0/gcc/match.pd

		// Note there are some instruction name differences.
		// We've translated those.  rshift is both types
		// of shift in GCC, but we have lshr and ashr here


		// =======
		// Integer Rules:
		// Line 168:
		// TODO -- how to get the precision (it's a constant --- note that this is sufficient for
		// proof of concept, but not for actually running the code)?
		// (31 is actually meant to be precision - 1).
		rewrite!("abs-expand-a"; "(abs ?x)" => "(xor (add (ashr ?x 31) ?x) (ashr ?x (31)))"),
		rewrite!("abs-expand-l"; "(abs ?x)" => "(xor (add (lshr ?x 31) ?x) (lshr ?x (31)))"),
		// Line: 280
		rewrite!("neg-to-mul"; "(neg ?x)" => "(mul ?x (const_-1))"),
		rewrite!("mul-to-neg"; "(mul ?x (const_-1))" => "(neg ?x)"), // TODO -- Thomas: This is cyclical,
		// should we consider it?
		// Line 320: TODO (IMO probably a somewhat useful one) (jcw)
		// Line 368: TODO -- only works for unsigned a.  Is there a way to check for this? (We can
		// probably skp this rule?)
		rewrite!("ashr-to-lsl-div"; "(ashr ?a ?b)" => "(div ?a (shl 1 ?b))"),
		rewrite!("lshr-to-lsl-div"; "(lshr ?a ?b)" => "(div ?a (shl 1 ?b))"),
		// Line 401:
		rewrite!("neg-to-div"; "(neg ?x)" => "(div ?x (const_-1))"),
		rewrite!("div-to-neg"; "(div ?x (const_-1))" => "(neg ?x)"), // TODO -- Thomas: this is cyclical,
		// see notes on the mul-to-neg case.

		// Line 422: Maybe useful? x / abs(x) => x < 0 ? -1 : 1?  Maybe too complex to match much?
		
		// Line 585: TODO -- is there a way to make it match constants only?
		// that would make this much simpler, as it could avoid introducing the lsl operation.
		rewrite!("ashr-to-logical-and"; "(ashr ?x ?a)" => "(div (and ?x (neg (shl const_2 ?a))) (shl const_2 ?a))"),
		rewrite!("lshr-to-logical-and"; "(lshr ?x ?a)" => "(div (and ?x (neg (shl const_2 ?a))) (shl const_2 ?a))"),
		// Line 685
		rewrite!("mod-to-neg-div-times"; "(mod ?x ?y)" => "(sub ?x (mul (div ?x ?y) ?y))"), // TODO
		// -- maybe that backwards? (jcw)

		// =========
		// Floating Point Rules.
		// Note that for FP rules, we generally assume -ffast-math or
		// equivlanet.  Otherwise, very limited rules apply, so not worthwhile.
		// Line 539:
		rewrite!("fneg-to-fdiv"; "(fneg ?x)" => "(fdiv ?x (const_-1))"),
		rewrite!("fdiv-to-fneg"; "(fdiv ?x (const_-1))" => "(fneg ?x)"),
		// Line 544:
		rewrite!("fmul-to-fdiv"; "(fdiv ?a (fmul ?b ?c))" => "(fdiv (fdiv ?a ?b) ?c)"), // Other
		// driection of that may be useful?
		// Line 558:
		rewrite!("fmul-to-fdiv-2"; "(fmul (fdiv ?a ?b) ?c)" => "(fdiv ?a (fdiv ?b ?c))"),

		// TODO --- note that there are a lot of rules around line 700 that may or may not be
		// useful if we encounter library calls to math.h.

		// TODO--- Useful rules copied up to line 1000, copy the remaining rules (jcw)

		// Other standard rules:

		rewrite!("commute-add"; "(add ?x ?y)" => "(add ?y ?x)"),
		rewrite!("commute-mul"; "(mul ?x ?y)" => "(mul ?y ?x)"),

		rewrite!("add-0"; "(add ?x 0)" => "?x"),
		rewrite!("mul-0"; "(mul ?x 0)" => "0"),
		rewrite!("mul-1"; "(mul ?x 1)" => "?x"),
	]
}

mod tests {
    use crate::{SymbolLang as S, *};
    use std::str::FromStr;

    type EGraph = crate::EGraph<S, ()>;

    #[test]
    fn fadd_rewrite() {
        create::init_logger()

            let mut egraph = EGraph::default()

            let x = egraph.add(S::leaf("x"));
            let y = egraph.add(S::leaf("y"));
            let mul = egraph.add(S::new("*", vec![x, y]));

            let 
    }
}
