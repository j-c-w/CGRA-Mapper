use egg::*;

pub(crate) fn rules() -> Vec<Rewrite<SymbolLang, ()>> {
    vec![
		// Rules we came up with:
		rewrite!("sub-to-add-neg"; "(sub ?x ?y)" => "(add ?x (mul (const_-1) ?y))"),

		// Rules from GCC (these are from :
		// https://github.com/gcc-mirror/gcc/blob/master/gcc/match.pd commit https://github.com/gcc-mirror/gcc/blob/7690bee9f36ee02b7ad0b8a7e7a3e08357890dc0/gcc/match.pd


		// =======
		// Integer Rules:
		// Line 168:
		// TODO -- how to get the precision (it's a constant --- note that this is sufficient for
		// proof of concept, but not for actually running the code)?
		// (31 is actually meant to be precision - 1).
		rewrite!("abs-expand"; "(abs ?x)" => "(xor (add (rsl ?x 31) ?x) (rsl ?x (31)))"),
		// Line: 280
		rewrite!("neg-to-mul"; "(neg ?x)" => "(mul ?x (const_-1))"),
		rewrite!("mul-to-neg"; "(mul ?x (const_-1))" => "(neg ?x)"), // TODO -- Thomas: This is cyclical,
		// should we consider it?
		// Line 320: TODO (IMO probably a somewhat useful one) (jcw)
		// Line 368: TODO -- only works for unsigned a.  Is there a way to check for this? (We can
		// probably skp this rule?)
		rewrite!("rsl-to-lsl-div"; "(rsl ?a ?b)" => "(div ?a (lsl 1 ?b))"),
		// Line 401:
		rewrite!("neg-to-div"; "(neg ?x)" => "(div ?x (const_-1))"),
		rewrite!("div-to-neg"; "(div ?x (const_-1))" => "(neg ?x)"), // TODO -- Thomas: this is cyclical,
		// see notes on the mul-to-neg case.

		// Line 422: Maybe useful? x / abs(x) => x < 0 ? -1 : 1?  Maybe too complex to match much?
		
		// Line 585: TODO -- is there a way to make it match constants only?
		// that would make this much simpler, as it could avoid introducing the lsl operation.
		rewrite!("rsl-to-logical-and"; "(rsl ?x ?a)" => "(div (and ?x (neg (2 lsl ?a))) (2 lsl ?a))"),
		// Line 685
		rewrite!("mod-to-neg-div-times"; "(mod ?x ?y)" => "(sub ?x (mul (div ?x ?y) ?y))"), // TODO
		// -- maybe that backwards? (jcw)

		// =========
		// Floating Point Rules.
		// Note that for FP rules, we generally assume -ffast-math or
		// equivlanet.  Otherwise, very limited rules apply, so not worthwhile.
		// Line 539:
		rewrite!("fneg-to-fdiv"; "(fneg ?x)" => "(fdiv ?x (const_-1.0))"),
		rewrite!("fdiv-to-fneg"; "(fdiv ?x (const_-1.0))" => "(fneg ?x)"),
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