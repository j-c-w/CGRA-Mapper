use egg::*;

// This set of rules assumes all logical operations are just boolean
// operations.
pub(crate) fn boolean_logic() -> Vec<Rewrite<SymbolLang, ()>> {
	vec![
		rewrite!("and-to-mul"; "(and ?x ?y)" => "(mul ?x ?y)"),
		// Logic with this one is, to be x =1 and y=1, we must
		// have not xor == 1 and add == 2 -- and that's the only way to get to
		// 3 in total.
		rewrite!("and-to-add-xor"; "(and ?x ?y)" => "(icmp (add (not (xor ?x ?y)) (add ?x ?y)) const_3)"),
		rewrite!("or-to-xor"; "(or ?x ?y)" => "(xor ?x ?y)"),
		// uses icmp neq
		rewrite!("or-to-add"; "(or ?x ?y)" => "(icmp (add ?x ?y) const_0)"),
        rewrite!("xor-to-or-and"; "(xor ?x ?y)" => "(sub (or ?x ?y) (and ?x ?y))"),// actually I think this one is generic.
        

        // Rewrite logic ops into icmp --- also should be only
        // boolean logic ops here.
        // I checked this one, it's the only non-trivial one in
        // this group of rules :)
        // The reason it's so complicated is because it tries
        // to support non-1 ?x/?y that are true
        // uses icmp eq
        rewrite!("xor-to-icmp"; "(xor ?x ?y)" => "(not (icmp ?x ?y))"),
        // uses icmp eq.
        rewrite!("not-to-icmp"; "(not ?x)" => "(icmp ?x const_0)"),
	]

}

// This is a set of rules that would run with flags
// like ffast-math in gcc.
// Note except where ohterwise specified, these rules
// are takne from GCC.
pub(crate) fn fp_rules() -> Vec<Rewrite<SymbolLang, ()>> {
	vec![
		// =========
		// Floating Point Rules.
		// Note that for FP rules, we generally assume -ffast-math or
		// equivlanet.  Otherwise, very limited rules apply, so not worthwhile.
		// Line 539:
		rewrite!("fneg-to-fdiv"; "(fneg ?x)" => "(fdiv ?x (const_-1))"),
		rewrite!("fdiv-to-fneg"; "(fdiv ?x (const_-1))" => "(fneg ?x)"),
		// Line 544:
		rewrite!("fmul-to-fdiv"; "(fdiv ?a (fmul ?b ?c))" => "(fdiv (fdiv ?a ?b) ?c)"), // Other
		rewrite!("fmul-to-fdiv-2"; "(fmul ?a ?b)" => "(fdiv ?a (fdiv const_1 ?b))"),
		// driection of that may be useful?
		// Line 558:
		rewrite!("fmul-to-fdiv-2"; "(fmul (fdiv ?a ?b) ?c)" => "(fdiv ?a (fdiv ?b ?c))"),
		// Various FP math.h function rules from line 5965


		// TODO --- note that there are a lot of rules around line 700 that may or may not be
		// useful if we encounter library calls to math.h.

		// TODO--- Useful rules copied up to line 1000, copy the remaining rules (jcw)

	]
}

// These are generally applicable, alwaystrue, integer rules.
pub(crate) fn rules() -> Vec<Rewrite<SymbolLang, ()>> {
    vec![
		// Rules we came up with:
		// Note: also in the GCC reles (1235)
		rewrite!("sub-to-add-neg"; "(sub ?x ?y)" => "(add ?x (mul const_-1 ?y))"),
        rewrite!("add-to-sub-neg"; "(add ?x ?y)" => "(sub ?x (mul const_-1 ?y))"),
		// This is in GCC also (3889)
        rewrite!("mul-to-neg"; "(mul const_-1 ?y)" => "(neg ?y)"),
        rewrite!("lsh-to-lshr-mul"; "(lsh ?x ?y)" => "(mul ?x (lshr const_IntMax (sub const_32 ?y)))"),
        rewrite!("lsh-to-ashr-mul"; "(lsh ?x ?y)" => "(mul ?x (ashr const_IntMax (sub const_32 ?y)))"),
		// This is also in the GCC rules.
		rewrite!("shl-const-to-mul"; "(shl ?x (Constant))" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div"; "(ashr ?x Constant)" => "(div ?x Constant)"),
		rewrite!("lshr-const-to-div"; "(lshr ?x Constant)" => "(div ?x Constant)"), // Same thing,
		// but would use a differenc onstant obviously.

        // Add into the highest bit leaves you with the equivalent
        // of a negation :)
        rewrite!("neg-to-add"; "(neg ?x)" => "(add const_2pow32 ?x)"),
		// The const here is sum_{lowest extended bit}^{highest extended bit} 2^n
		rewrite!("zext-to-sext"; "(zext ?x)" => "(and (sext ?x) const_something)"),
		rewrite!("zext-to-bitcast"; "(zext ?x)" => "(bitcast ?x)"), // Think these are the same?
		// Sext is sign extend.  So, first extend using bitcast
		// (which we get for free on all nodes, since it's just
		// widening), then turn ?x into -1 if x is -ve and 1 if
		// it's +ve and multiply.
        // first icmp is icmp slt, second is sgt
		rewrite!("sext-to-logic"; "(sext ?x)" => "(mul (bitcast ?x) (add (neg (icmp ?x const_0)
            (icmp ?x const_0))))"),
		// Also do a version w/out the mul, since
		// we know that the result of the icmp must be -1, 0 or 1
		rewrite!("sext-to-logic-2"; "(sext ?x)" => "(or (bitcast ?x) (lsh (neg (icmp ?x const_0))
            const_31))"),

		// note that there are in the GCC rules in more
		// complex ways.
        rewrite!("and-to-or"; "(and ?x ?y)" => "(not (or (not ?x) (not ?y)))"),
        rewrite!("or-to-and"; "(or ?x ?y)" => "(not (and (not ?x) (not ?y)))"),

        // FP rule  we came up with:
        // Not intended to be correct: require -funsafe-math-operations or similar.
        // Apply a similar threshold to GCC for 'correctness' here.
        rewrite!("fp-sub-to-add-neg"; "(fsub ?x ?y)" => "(fadd ?x (fmul const_-1 ?y))"),
        rewrite!("fp-add-to-sub"; "(fadd ?x ?y)" => "(fsub ?x (fmul const_-1 ?y))"),
        // Copy with Control-flow-edge options
        rewrite!("fp-add-to-sub"; "(fadd ?x ?y ?z)" => "(fsub ?x (fmul const_-1 ?y) ?z)"),
        rewrite!("fp-add-to-neg"; "(fadd ?x ?y)" => "(fsub ?x (fneg ?y))"),
        rewrite!("fp-mul-to-neg"; "(fmul const_-1 ?y)" => "(fneg ?y)"),
        // I think this might even infringe GCC's limits for ffast-math...
        rewrite!("fp-mul-to-div"; "(fmul ?x ?y)" => "(fdiv ?x (fdiv const_1 ?y))"),

		// Not sure what the 'not' in LLVM is called.
		// This one is a logical not.
		rewrite!("not-to-xor"; "(not ?x)" => "(xor ?x const_0)"),
		// Similar rules from GCC's rewrite rules. (line 1790)
		rewrite!("neg-to-sub"; "(neg ?a)" => "(not (sub ?a const_-1))"),
		rewrite!("not-to-sub"; "(not ?a)" => "(neg (add ?a const_1))"),
		// Line 1810:
		rewrite!("neg-to-add"; "(neg ?a)" => "(not (add ?a const_-1))"),

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

		// Line 1019
		rewrite!("xor-to-not-or"; "(xor ?x ?y)" => "(or (and ?x (not ?y)) (and (not ?x) ?y))"),
		rewrite!("xot-to-add-and"; "(xor ?x ?y)" => "(add (and ?x (not ?y)) (and (not ?x) ?y))"),
		// Line 1044:
		rewrite!("or-to-and-xor"; "(or ?x ?y)" => "(xor (and (not ?x) ?y) ?x)"),
		// Line 1291:
		rewrite!("neg-to-xor"; "(neg ?x)" => "(xor ?x const_-1)"),
		// Abs rule on 1541

		// Line 1790: -- possibly useful?

		// Other standard rules:

		rewrite!("commute-add"; "(add ?x ?y)" => "(add ?y ?x)"),
		rewrite!("commute-mul"; "(mul ?x ?y)" => "(mul ?y ?x)"),

		rewrite!("add-0"; "(add ?x 0)" => "?x"),
		rewrite!("mul-0"; "(mul ?x 0)" => "0"),
		rewrite!("mul-1"; "(mul ?x 1)" => "?x"),
	]
}

pub(crate) fn gcc_rules() -> Vec<Rewrite<SymbolLang, ()>> {
	let mut intrules = rules().clone();
	let fprules = fp_rules().clone();
	intrules.extend(fprules);
	intrules
}