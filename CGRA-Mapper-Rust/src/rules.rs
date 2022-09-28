use egg::*;

pub(crate) fn stochastic() -> Vec<Rewrite<SymbolLang, ()>> {
	vec![
		rewrite!("mul-to-and"; "(mul ?x ?y)" => "(and ?x ?y)"),
		// We have a case study of Wang 2022 DATE, which uses a custom
		// isc-mul node --- IMO wouldnae be unfair to just pretend
		// it's an add, but better to be explicit than implicit :)
		// The paper also notes that each node supports muls of different
		// accuracies, so allow rewrites to any of those. (For completeness,
		// it doesnt' make any diff to this algorithm --- we'd need a better
		// cost model to take advantage)
		rewrite!("mul-to-isc-and"; "(mul ?x ?y)" => "(isc_mul ?x ?y)"),
		// IDK if any CGRA actually has support for a mux function
		// but suppose they could do (see https://arxiv.org/pdf/2108.12326.pdf)
		// Note that the difficulty is obtaining the third stream
		// for the bit-wise selection from the add.
		rewrite!("add-to-mux"; "(add ?x ?y)" => "(mux ?x ?y)"),
		// See note above about Wang 2022
		rewrite!("add-to-mux-wang"; "(add ?x ?y)" => "(add_shifter ?x ?y)"),
		// Stochastic computing tolerates bit-errors very well,
		// we can introduce these error-inducing things
		// to get more compiles:
		// Perhaps these should really be under a different flag.
		// rewrite!("lshr-to-ashr"; "(lshr ?x ?y)" => "(ashr ?x ?y)"),
		// rewrite!("ashr-to-lshr"; "(ashr ?x ?y)" => "(lshr ?x ?y)"),
		// rewrite!("or-to-xor"; "(or ?x ?y)" => "(xor ?x ?y)"),
		// rewrite!("xor-to-or"; "(xor ?x ?y)" => "(or ?x ?y)")
		// Really, I'd like to include those, but the stochastic computing
		// people usually do a whole analysis before they
		// propose stuff like this...
	]
}

// This set of rules assumes all logical operations are just boolean
// operations.
pub(crate) fn boolean_logic() -> Vec<Rewrite<SymbolLang, ()>> {
	vec![
		rewrite!("and-to-mul"; "(and ?x ?y)" => "(mul ?x ?y)"),
		// Logic with this one is, to be x =1 and y=1, we must
		// have not xor == 1 and add == 2 -- and that's the only way to get to
		// 3 in total.
		rewrite!("and-to-add-xor"; "(and ?x ?y)" => "(icmp (add (not (xor ?x ?y)) (add ?x ?y)) const_3)"),
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
		rewrite!("fp-neg-to-sub"; "(fneg ?x)" => "(fsub const_0 ?x)"),
		rewrite!("fp-neg-to-mul"; "(fneg ?x)" => "(fmul const_-1 ?x)"),

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

	]
}

// These are generally applicable, alwaystrue, integer rules.
pub(crate) fn rules() -> Vec<Rewrite<SymbolLang, ()>> {
    vec![
		// Rules we came up with:
		// Note: also in the GCC reles (1235)
		rewrite!("sub-to-add-neg"; "(sub ?x ?y)" => "(add ?x (neg ?y))"),
        rewrite!("add-to-sub-neg"; "(add ?x ?y)" => "(sub ?x (neg ?y))"),
		rewrite!("sub-swap"; "(sub ?x ?y)" => "(neg (sub ?y ?x))"),
		// This is in GCC also (3889)
        rewrite!("mul-to-neg"; "(mul const_-1 ?y)" => "(neg ?y)"),
        rewrite!("neg-to-mul"; "(neg ?y)" => "(mul const_-1 ?y)"),
		// Const here is 0
		rewrite!("neg-to-sub"; "(neg ?y)" => "(sub Constant ?y)"),
		// First constant is Int Max, second is 32
        rewrite!("shl-to-lshr-mul"; "(shl ?x ?y)" => "(mul ?x (lshr Constant (sub Constant ?y)))"),
        rewrite!("shl-to-ashr-mul"; "(shl ?x ?y)" => "(mul ?x (ashr Constant (sub Constant ?y)))"),
		// This is also in the GCC rules --- note we should obviously handle this
		// better -- just do the obvious cases.
		rewrite!("shl-const-to-mul"; "(shl ?x const_1)" => "(mul ?x const_2)"),
		rewrite!("ashr-const-to-div"; "(ashr ?x const_1)" => "(sdiv ?x const_2)"),
		rewrite!("lshr-const-to-div"; "(lshr ?x const_1)" => "(sdiv ?x const_2)"),
		rewrite!("shl-const-to-mul-2"; "(shl ?x const_2)" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div-2"; "(ashr ?x const_2)" => "(sdiv ?x Constant)"),
		rewrite!("lshr-const-to-div-2"; "(lshr ?x const_2)" => "(sdiv ?x Constant)"),
		rewrite!("shl-const-to-mul-3"; "(shl ?x const_3)" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div-3"; "(ashr ?x const_3)" => "(sdiv ?x Constant)"),
		rewrite!("lshr-const-to-div-3"; "(lshr ?x const_3)" => "(sdiv ?x Constant)"),
		rewrite!("shl-const-to-mul-4"; "(shl ?x const_4)" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div-4"; "(ashr ?x const_4)" => "(sdiv ?x Constant)"),
		rewrite!("lshr-const-to-div-4"; "(lshr ?x const_4)" => "(sdiv ?x Constant)"),
		rewrite!("shl-const-to-mul-5"; "(shl ?x const_5)" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div-5"; "(ashr ?x const_5)" => "(sdiv ?x Constant)"),
		rewrite!("lshr-const-to-div-5"; "(lshr ?x const_5)" => "(sdiv ?x Constant)"),
		rewrite!("shl-const-to-mul-6"; "(shl ?x const_6)" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div-6"; "(ashr ?x const_6)" => "(sdiv ?x Constant)"),
		rewrite!("lshr-const-to-div-6"; "(lshr ?x const_6)" => "(sdiv ?x Constant)"),
		rewrite!("shl-const-to-mul-7"; "(shl ?x const_7)" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div-7"; "(ashr ?x const_7)" => "(sdiv ?x Constant)"),
		rewrite!("lshr-const-to-div-7"; "(lshr ?x const_7)" => "(sdiv ?x Constant)"),
		rewrite!("shl-const-to-mul-8"; "(shl ?x const_8)" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div-8"; "(ashr ?x const_8)" => "(sdiv ?x Constant)"),
		rewrite!("lshr-const-to-div-8"; "(lshr ?x const_8)" => "(sdiv ?x Constant)"),
		rewrite!("shl-const-to-mul-9"; "(shl ?x const_9)" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div-9"; "(ashr ?x const_9)" => "(sdiv ?x Constant)"),
		rewrite!("lshr-const-to-div-9"; "(lshr ?x const_9)" => "(sdiv ?x Constant)"),
		rewrite!("shl-const-to-mul-10"; "(shl ?x const_10)" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div-10"; "(ashr ?x const_10)" => "(sdiv ?x Constant)"),
		rewrite!("lshr-const-to-div-10"; "(lshr ?x const_10)" => "(sdiv ?x Constant)"),
		rewrite!("shl-const-to-mul-11"; "(shl ?x const_11)" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div-11"; "(ashr ?x const_11)" => "(sdiv ?x Constant)"),
		rewrite!("lshr-const-to-div-11"; "(lshr ?x const_11)" => "(sdiv ?x Constant)"),
		rewrite!("shl-const-to-mul-12"; "(shl ?x const_12)" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div-12"; "(ashr ?x const_12)" => "(sdiv ?x Constant)"),
		rewrite!("lshr-const-to-div-12"; "(lshr ?x const_12)" => "(sdiv ?x Constant)"),
		rewrite!("shl-const-to-mul-13"; "(shl ?x const_13)" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div-13"; "(ashr ?x const_13)" => "(sdiv ?x Constant)"),
		rewrite!("lshr-const-to-div-13"; "(lshr ?x const_13)" => "(sdiv ?x Constant)"),
		rewrite!("shl-const-to-mul-14"; "(shl ?x const_14)" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div-14"; "(ashr ?x const_14)" => "(sdiv ?x Constant)"),
		rewrite!("lshr-const-to-div-14"; "(lshr ?x const_14)" => "(sdiv ?x Constant)"),
		rewrite!("shl-const-to-mul-15"; "(shl ?x const_15)" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div-15"; "(ashr ?x const_15)" => "(sdiv ?x Constant)"),
		rewrite!("lshr-const-to-div-15"; "(lshr ?x const_15)" => "(sdiv ?x Constant)"),
		rewrite!("shl-const-to-mul-16"; "(shl ?x const_16)" => "(mul ?x Constant)"),
		rewrite!("ashr-const-to-div-16"; "(ashr ?x const_16)" => "(sdiv ?x Constant)"),
		rewrite!("lshr-const-to-div-16"; "(lshr ?x const_16)" => "(sdiv ?x Constant)"),
		// End of the stupid expansion of the shifting rules.

        // Add into the highest bit leaves you with the equivalent
        // of a negation (I think it doesn't?)
        // rewrite!("neg-to-add"; "(neg ?x)" => "(add const_2pow32 ?x)"),
		// The const here is sum_{lowest extended bit}^{highest extended bit} 2^n
		rewrite!("zext-to-sext"; "(zext ?x)" => "(and (sext ?x) const_something)"),
		rewrite!("to-bitcast"; "(and (sext ?x) const_something)" => "(bitcast ?x)"), // The same enough that we assume the hw for one can support the other.
		// Sext is sign extend.  So, first extend using bitcast
		// (which we get for free on all nodes, since it's just
		// widening), then turn ?x into -1 if x is -ve and 1 if
		// it's +ve and multiply.
        // first icmp is icmp slt, second is sgt
		rewrite!("sext-to-logic"; "(sext ?x)" => "(mul (bitcast ?x) (add (neg (icmp ?x const_0) (icmp ?x const_0))))"),
		// Also do a version w/out the mul, since
		rewrite!("to-logic-2"; "(mul (bitcast ?x) (add (neg (icmp ?x const_0) (icmp ?x const_0))))" => "(or (bitcast ?x) (shl (neg (icmp ?x const_0)) const_31))"),

		// note that there are in the GCC rules in more
		// complex ways.
        rewrite!("and-to-or"; "(and ?x ?y)" => "(not (or (not ?x) (not ?y)))"),
        rewrite!("or-to-and"; "(or ?x ?y)" => "(not (and (not ?x) (not ?y)))"),

		// See https://stackoverflow.com/questions/2982729/is-it-possible-to-implement-bitwise-operators-using-integer-arithmetic
		// Constant is 2^bit size. note that it's possible that not all models of CGRA support
		// this.
		// Not 100% clear how to write this---maybe it needs a br also?  Regardless,
		// We always have br nodes for the loop header.
		rewrite!("shl-to-mul-generic"; "(shl ?x ?y)" => "(phi (icmp ?y Constant) (load (mul ?x (add
			?y Constant))))"),
		rewrite!("rshl-to-div-generic"; "(shl ?x ?y)" => "(phi (icmp ?y Constant) (phi (icmp ?x
		const_0) const_0 const_-1) (phi (icmp ?x const_0) (sub (load (sub Constant ?y)) (div (add ?x Constant) (load (add ?y
		Constant))))) (div ?x (load (add ?y Constant)))))"),
		// TODO -- it might be good to handle the AND -> ADD loops they propose in that question.
		// We need a better cost model for that I think.

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

		// Rules that are in GCC, but needed reformatting due to poor hanlding of
		// constants.  Obviously we could handle more cases.
		rewrite!("div-2"; "(sdiv ?x const_2)" => "(ashr ?x const_1)"),
		rewrite!("div-4"; "(sdiv ?x const_4)" => "(ashr ?x const_2)"),
		rewrite!("div-8"; "(sdiv ?x const_8)" => "(ashr ?x const_3)"),
		rewrite!("div-16"; "(sdiv ?x const_16)" => "(ashr ?x const_4)"),
		rewrite!("div-32"; "(sdiv ?x const_32)" => "(ashr ?x const_5)"),
		rewrite!("div-64"; "(sdiv ?x const_64)" => "(ashr ?x const_6)"),

		rewrite!("udiv-2"; "(udiv ?x const_2)" => "(lshr ?x const_1)"),
		rewrite!("udiv-4"; "(udiv ?x const_4)" => "(lshr ?x const_2)"),
		rewrite!("udiv-8"; "(udiv ?x const_8)" => "(lshr ?x const_3)"),
		rewrite!("udiv-16"; "(udiv ?x const_16)" => "(lshr ?x const_4)"),
		rewrite!("udiv-32"; "(udiv ?x const_32)" => "(lshr ?x const_5)"),
		rewrite!("udiv-64"; "(udiv ?x const_64)" => "(lshr ?x const_6)"),

		rewrite!("mul-2"; "(mul ?x const_2)" => "(shl ?x const_1)"),
		rewrite!("mul-4"; "(mul ?x const_4)" => "(shl ?x const_2)"),
		rewrite!("mul-8"; "(mul ?x const_8)" => "(shl ?x const_3)"),
		rewrite!("mul-16"; "(mul ?x const_16)" => "(shl ?x const_4)"),
		rewrite!("mul-32"; "(mul ?x const_32)" => "(shl ?x const_5)"),
		rewrite!("mul-64"; "(mul ?x const_64)" => "(shl ?x const_6)"),

		rewrite!("add-1"; "(add ?x ?x)" => "(mul ?x const_2)"),
		// These aren't in GCC I don't htink --- they could be though.
		rewrite!("mul-1"; "(mul ?x const_1)" => "?x"),
		rewrite!("mul-3"; "(mul ?x const_3)" => "(add (mul ?x const_2) ?x)"),
		rewrite!("mul-5"; "(mul ?x const_5)" => "(add (mul ?x const_4) ?x)"),
		rewrite!("mul-6"; "(mul ?x const_6)" => "(add (mul ?x const_4) (add ?x ?x))"),
		rewrite!("mul-7"; "(mul ?x const_7)" => "(sub (mul ?x const_8) ?x)"),
		rewrite!("mul-9"; "(mul ?x const_9)" => "(add (mul ?x const_8) ?x)"),
		// Again, could obviously support more of those --just hanlde hte comon cases here.
		// also handle the case study example:
		rewrite!("mul-20"; "(mul ?x const_20)" => "(add (mul ?x const_16) (mul ?x const_4))"),

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
		// Line: 280 (as above)
		// rewrite!("neg-to-mul"; "(neg ?x)" => "(mul ?x (const_-1))"),
		// rewrite!("mul-to-neg"; "(mul ?x (const_-1))" => "(neg ?x)"), // TODO -- Thomas: This is cyclical,
		// should we consider it?
		// Line 320: TODO (IMO probably a somewhat useful one) (jcw)
		// Line 368: TODO -- only works for unsigned a.  Is there a way to check for this? (We can
		// probably skp this rule?)
		rewrite!("ashr-to-lsl-div"; "(ashr ?a ?b)" => "(sdiv ?a (shl const_1 ?b))"),
		rewrite!("lshr-to-lsl-div"; "(lshr ?a ?b)" => "(sdiv ?a (shl const_1 ?b))"),
		// Line 401:
		rewrite!("neg-to-div"; "(neg ?x)" => "(sdiv ?x (const_-1))"),
		// rewrite!("div-to-neg"; "(sdiv ?x (const_-1))" => "(neg ?x)"),

		// Line 422: Maybe useful? x / abs(x) => x < 0 ? -1 : 1?  Maybe too complex to match much?
		
		// Line 585: TODO -- is there a way to make it match constants only?
		// that would make this much simpler, as it could avoid introducing the lsl operation.
		rewrite!("ashr-to-logical-and"; "(ashr ?x ?a)" => "(sdiv (and ?x (neg (shl const_2 ?a))) (shl const_2 ?a))"),
		rewrite!("lshr-to-logical-and"; "(lshr ?x ?a)" => "(sdiv (and ?x (neg (shl const_2 ?a))) (shl const_2 ?a))"),
		// Line 685
		rewrite!("mod-to-neg-div-times"; "(srem ?x ?y)" => "(sub ?x (mul (sdiv ?x ?y) ?y))"), // TODO
		rewrite!("mod-to-neg-div-times"; "(urem ?x ?y)" => "(sub ?x (mul (udiv ?x ?y) ?y))"), // TODO
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

// This is the rules in the style in which they appear in match.pd.
// (i.e. to cannonicalize rather than to rewrite for HW use)
pub(crate) fn gcc_style_rules() -> Vec<Rewrite<SymbolLang, ()>> {
    vec![
		// Rules we came up with:
		// Note: also in the GCC reles (1235)
		rewrite!("sub-to-add-neg"; "(add ?x (neg ?y))" => "(sub ?x ?y)"),
        rewrite!("add-to-sub-neg"; "(sub ?x (neg ?y))" => "(add ?x ?y)"),
		// rewrite!("sub-swap"; "(neg (sub ?y ?x))" => "(sub ?x ?y)"),
		// This is in GCC also (3889)
        rewrite!("mul-to-neg"; "(mul const_-1 ?y)" => "(neg ?y)"),
        // rewrite!("neg-to-mul"; "(neg ?y)" => "(mul const_-1 ?y)"),
		// Const here is 0
		rewrite!("neg-to-sub"; "(sub Constant ?y)" => "(neg ?y)"),
		// First constant is Int Max, second is 32
        rewrite!("shl-to-lshr-mul"; "(mul ?x (lshr Constant (sub const_32 ?y)))" => "(shl ?x ?y)"),
        rewrite!("shl-to-ashr-mul"; "(mul ?x (ashr Constant (sub const_int_max ?y)))" => "(shl ?x ?y)"),
		// This is also in the GCC rules --- note we should obviously handle this
		// better -- just do the obvious cases.
		rewrite!("shl-const-to-mul"; "(mul ?x const_2)" => "(shl ?x const_1)"),
		rewrite!("ashr-const-to-div"; "(sdiv ?x const_2)" => "(ashr ?x const_1)"),
		rewrite!("lshr-const-to-div"; "(sdiv ?x const_2)" => "(lshr ?x const_1)"),
		rewrite!("shl-const-to-mul-2"; "(mul ?x const_4)" => "(shl ?x const_2)"),
		rewrite!("ashr-const-to-div-2"; "(sdiv ?x const_4)" => "(ashr ?x const_2)"),
		rewrite!("lshr-const-to-div-2"; "(sdiv ?x const_4)" => "(lshr ?x const_2)"),
		rewrite!("shl-const-to-mul-3"; "(mul ?x const_8)" => "(shl ?x const_3)"),
		rewrite!("ashr-const-to-div-3"; "(sdiv ?x const_8)" => "(ashr ?x const_3)"),
		rewrite!("lshr-const-to-div-3"; "(sdiv ?x const_8)" => "(lshr ?x const_3)"),
		rewrite!("shl-const-to-mul-4"; "(mul ?x const_16)" => "(shl ?x const_4)"),
		rewrite!("ashr-const-to-div-4"; "(sdiv ?x const_16)" => "(ashr ?x const_4)"),
		rewrite!("lshr-const-to-div-4"; "(sdiv ?x const_16)" => "(lshr ?x const_4)"),
		rewrite!("shl-const-to-mul-5"; "(mul ?x const_32)" => "(shl ?x const_5)"),
		rewrite!("ashr-const-to-div-5"; "(sdiv ?x const_32)" => "(ashr ?x const_5)"),
		rewrite!("lshr-const-to-div-5"; "(sdiv ?x const_32)" => "(lshr ?x const_5)"),
		rewrite!("shl-const-to-mul-6"; "(mul ?x const_64)" => "(shl ?x const_6)"),
		rewrite!("ashr-const-to-div-6"; "(sdiv ?x const_64)" => "(ashr ?x const_6)"),
		rewrite!("lshr-const-to-div-6"; "(sdiv ?x const_64)" => "(lshr ?x const_6)"),
		rewrite!("shl-const-to-mul-7"; "(mul ?x const_128)" => "(shl ?x const_7)"),
		rewrite!("ashr-const-to-div-7"; "(sdiv ?x const_128)" => "(ashr ?x const_7)"),
		rewrite!("lshr-const-to-div-7"; "(sdiv ?x const_128)" => "(lshr ?x const_7)"),
		rewrite!("shl-const-to-mul-8"; "(mul ?x const_256)" => "(shl ?x const_8)"),
		rewrite!("ashr-const-to-div-8"; "(sdiv ?x const_256)" => "(ashr ?x const_8)"),
		rewrite!("lshr-const-to-div-8"; "(sdiv ?x const_256)" => "(lshr ?x const_8)"),
		rewrite!("shl-const-to-mul-9"; "(mul ?x const_512)" => "(shl ?x const_9)"),
		rewrite!("ashr-const-to-div-9"; "(sdiv ?x const_512)" => "(ashr ?x const_9)"),
		rewrite!("lshr-const-to-div-9"; "(sdiv ?x const_512)" => "(lshr ?x const_9)"),
		rewrite!("shl-const-to-mul-10"; "(mul ?x const_1024)" => "(shl ?x const_10)"),
		rewrite!("ashr-const-to-div-10"; "(sdiv ?x const_1024)" => "(ashr ?x const_10)"),
		rewrite!("lshr-const-to-div-10"; "(sdiv ?x const_1024)" => "(lshr ?x const_10)"),
		rewrite!("shl-const-to-mul-11"; "(mul ?x const_2048)" => "(shl ?x const_11)"),
		rewrite!("ashr-const-to-div-11"; "(sdiv ?x const_2048)" => "(ashr ?x const_11)"),
		rewrite!("lshr-const-to-div-11"; "(sdiv ?x const_2048)" => "(lshr ?x const_11)"),
		rewrite!("shl-const-to-mul-12"; "(mul ?x const_4096)" => "(shl ?x const_12)"),
		rewrite!("ashr-const-to-div-12"; "(sdiv ?x const_4096)" => "(ashr ?x const_12)"),
		rewrite!("lshr-const-to-div-12"; "(sdiv ?x const_4096)" => "(lshr ?x const_12)"),
		rewrite!("shl-const-to-mul-13"; "(mul ?x const_8192)" => "(shl ?x const_13)"),
		rewrite!("ashr-const-to-div-13"; "(sdiv ?x const_8192)" => "(ashr ?x const_13)"),
		rewrite!("lshr-const-to-div-13"; "(sdiv ?x const_8192)" => "(lshr ?x const_13)"),
		rewrite!("shl-const-to-mul-14"; "(mul ?x const_16384)" => "(shl ?x const_14)"),
		rewrite!("ashr-const-to-div-14"; "(sdiv ?x const_16384)" => "(ashr ?x const_14)"),
		rewrite!("lshr-const-to-div-14"; "(sdiv ?x const_16384)" => "(lshr ?x const_14)"),
		rewrite!("shl-const-to-mul-15"; "(mul ?x const_32768)" => "(shl ?x const_15)"),
		rewrite!("ashr-const-to-div-15"; "(sdiv ?x const_32768)" => "(ashr ?x const_15)"),
		rewrite!("lshr-const-to-div-15"; "(sdiv ?x const_32768)" => "(lshr ?x const_15)"),
		rewrite!("shl-const-to-mul-16"; "(mul ?x const_64536)" => "(shl ?x const_16)"),
		rewrite!("ashr-const-to-div-16"; "(sdiv ?x const_64536)" => "(ashr ?x const_16)"),
		rewrite!("lshr-const-to-div-16"; "(sdiv ?x const_64536)" => "(lshr ?x const_16)"),
		// End of the stupid expansion of the shifting rules.

        // Add into the highest bit leaves you with the equivalent
        // of a negation (I think it doesn't?)
        // rewrite!("neg-to-add"; "(neg ?x)" => "(add const_2pow32 ?x)"),
		// The const here is sum_{lowest extended bit}^{highest extended bit} 2^n
		// Leave these in the LLVM rules becuase these are here to deal with the issues
		// these very llvm-specific instructions cause with the target representations.
		rewrite!("zext-to-sext"; "(zext ?x)" => "(and (sext ?x) const_something)"),
		rewrite!("to-bitcast"; "(and (sext ?x) const_something)" => "(bitcast ?x)"), // The same enough that we assume the hw for one can support the other.
		// Sext is sign extend.  So, first extend using bitcast
		// (which we get for free on all nodes, since it's just
		// widening), then turn ?x into -1 if x is -ve and 1 if
		// it's +ve and multiply.
        // first icmp is icmp slt, second is sgt
		// rewrite!("sext-to-logic"; "(sext ?x)" => "(mul (bitcast ?x) (add (neg (icmp ?x const_0) (icmp ?x const_0))))"),
		// Also do a version w/out the mul, since
		// rewrite!("to-logic-2"; "(mul (bitcast ?x) (add (neg (icmp ?x const_0) (icmp ?x const_0))))" => "(or (bitcast ?x) (shl (neg (icmp ?x const_0)) const_31))"),

		// note that there are in the GCC rules in more
		// complex ways.
        rewrite!("and-to-or"; "(not (or (not ?x) (not ?y)))" => "(and ?x ?y)"),
        rewrite!("or-to-and"; "(not (and (not ?x) (not ?y)))" => "(or ?x ?y)"),

		// See https://stackoverflow.com/questions/2982729/is-it-possible-to-implement-bitwise-operators-using-integer-arithmetic
		// Constant is 2^bit size. note that it's possible that not all models of CGRA support
		// this.
		// Not 100% clear how to write this---maybe it needs a br also?  Regardless,
		// We always have br nodes for the loop header.
		rewrite!("shl-to-mul-generic"; "(phi (icmp ?y Constant) (load (mul ?x (add ?y Constant))))" => "(shl ?x ?y)"),
		rewrite!("rshl-to-div-generic"; "(phi (icmp ?y Constant) (phi (icmp ?x const_0) const_0 const_-1) (phi (icmp ?x const_0) (sub (load (sub Constant ?y)) (div (add ?x Constant) (load (add ?y
		Constant))))) (div ?x (load (add ?y Constant))))" => "(shl ?x ?y))"),
		// TODO -- it might be good to handle the AND -> ADD loops they propose in that question.
		// We need a better cost model for that I think.

		// Not sure what the 'not' in LLVM is called.
		// This one is a logical not.
		rewrite!("not-to-xor"; "(xor ?x const_0)" => "(not ?x)"),
		// Similar rules from GCC's rewrite rules. (line 1790)
		rewrite!("neg-to-sub"; "(not (sub ?a const_-1))" => "(neg ?a)"),
		rewrite!("not-to-sub"; "(neg (add ?a const_1))" => "(not ?a)"),
		// Line 1810:
		rewrite!("neg-to-add"; "(not (add ?a const_-1))" => "(neg ?a)"),

        // Integer add into the correct spot in FP gives you
        // equivalent of negation
        // Note that this only applies for IEEE format (or other
        // formats where the sign bit is the top one
        // and can overflow)
        rewrite!("fp-fneg-to-add"; "(add const_2pow32 ?x)" => "(fneg ?x)"),

		// Rules that are in GCC, but needed reformatting due to poor hanlding of
		// constants.  Obviously we could handle more cases.
		rewrite!("div-2"; "(sdiv ?x const_2)" => "(ashr ?x const_1)"),
		rewrite!("div-4"; "(sdiv ?x const_4)" => "(ashr ?x const_2)"),
		rewrite!("div-8"; "(sdiv ?x const_8)" => "(ashr ?x const_3)"),
		rewrite!("div-16"; "(sdiv ?x const_16)" => "(ashr ?x const_4)"),
		rewrite!("div-32"; "(sdiv ?x const_32)" => "(ashr ?x const_5)"),
		rewrite!("div-64"; "(sdiv ?x const_64)" => "(ashr ?x const_6)"),

		rewrite!("udiv-2"; "(udiv ?x const_2)" => "(lshr ?x const_1)"),
		rewrite!("udiv-4"; "(udiv ?x const_4)" => "(lshr ?x const_2)"),
		rewrite!("udiv-8"; "(udiv ?x const_8)" => "(lshr ?x const_3)"),
		rewrite!("udiv-16"; "(udiv ?x const_16)" => "(lshr ?x const_4)"),
		rewrite!("udiv-32"; "(udiv ?x const_32)" => "(lshr ?x const_5)"),
		rewrite!("udiv-64"; "(udiv ?x const_64)" => "(lshr ?x const_6)"),

		rewrite!("mul-2"; "(mul ?x const_2)" => "(shl ?x const_1)"),
		rewrite!("mul-4"; "(mul ?x const_4)" => "(shl ?x const_2)"),
		rewrite!("mul-8"; "(mul ?x const_8)" => "(shl ?x const_3)"),
		rewrite!("mul-16"; "(mul ?x const_16)" => "(shl ?x const_4)"),
		rewrite!("mul-32"; "(mul ?x const_32)" => "(shl ?x const_5)"),
		rewrite!("mul-64"; "(mul ?x const_64)" => "(shl ?x const_6)"),

		rewrite!("add-1"; "(mul ?x const_2)" => "(add ?x ?x)"),
		// These aren't in GCC I don't htink --- they could be though.
		rewrite!("mul-1"; "(mul ?x const_1)" => "?x"),
		rewrite!("mul-3"; "(add (mul ?x const_2) ?x)" => "(mul ?x const_3)"),
		rewrite!("mul-5"; "(add (mul ?x const_4) ?x)" => "(mul ?x const_5)"),
		rewrite!("mul-6"; "(add (mul ?x const_4) (add ?x ?x))" => "(mul ?x const_6)"),
		rewrite!("mul-7"; "(sub (mul ?x const_8) ?x)" => "(mul ?x const_7)"),
		rewrite!("mul-9"; "(add (mul ?x const_8) ?x)" => "(mul ?x const_9)"),
		// Again, could obviously support more of those --just hanlde hte comon cases here.
		rewrite!("mul-20"; "(add (mul ?x const_16) (mul ?x const_4))" => "(mul ?x const_20)"),

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
		rewrite!("abs-expand-a"; "(xor (add (ashr ?x const_31) ?x) (ashr ?x (31)))" => "(abs ?x)"),
		rewrite!("abs-expand-l"; "(xor (add (lshr ?x const_31) ?x) (lshr ?x (31)))" => "(abs ?x)"),
		// Line: 280 (as above)
		// rewrite!("neg-to-mul"; "(neg ?x)" => "(mul ?x (const_-1))"),
		// rewrite!("mul-to-neg"; "(mul ?x (const_-1))" => "(neg ?x)"), // TODO -- Thomas: This is cyclical,
		// should we consider it?
		// Line 320: TODO (IMO probably a somewhat useful one) (jcw)
		// Line 368: TODO -- only works for unsigned a.  Is there a way to check for this? (We can
		// probably skp this rule?)
		rewrite!("ashr-to-lsl-div"; "(sdiv ?a (shl const_1 ?b))" => "(ashr ?a ?b)"),
		rewrite!("lshr-to-lsl-div"; "(sdiv ?a (shl const_1 ?b))" => "(lshr ?a ?b)"),
		// Line 401:
		rewrite!("neg-to-div"; "(sdiv ?x (const_-1))" => "(neg ?x)"),
		// rewrite!("div-to-neg"; "(sdiv ?x (const_-1))" => "(neg ?x)"),

		// Line 422: Maybe useful? x / abs(x) => x < 0 ? -1 : 1?  Maybe too complex to match much?
		
		// Line 585: TODO -- is there a way to make it match constants only?
		// that would make this much simpler, as it could avoid introducing the lsl operation.
		rewrite!("ashr-to-logical-and"; "(sdiv (and ?x (neg (shl const_2 ?a))) (shl const_2 ?a))" => "(ashr ?x ?a)"),
		rewrite!("lshr-to-logical-and"; "(sdiv (and ?x (neg (shl const_2 ?a))) (shl const_2 ?a))" => "(lshr ?x ?a)"),
		// Line 685
		rewrite!("mod-to-neg-div-times"; "(sub ?x (mul (sdiv ?x ?y) ?y))" => "(srem ?x ?y)"), // TODO
		rewrite!("mod-to-neg-div-times"; "(sub ?x (mul (udiv ?x ?y) ?y))" => "(urem ?x ?y)"), // TODO
		// -- maybe that backwards? (jcw)

		// Line 1019
		rewrite!("xor-to-not-or"; "(or (and ?x (not ?y)) (and (not ?x) ?y))" => "(xor ?x ?y)"),
		rewrite!("xot-to-add-and"; "(add (and ?x (not ?y)) (and (not ?x) ?y))" => "(xor ?x ?y)"),
		// Line 1044:
		rewrite!("or-to-and-xor"; "(xor (and (not ?x) ?y) ?x)" => "(or ?x ?y)"),
		// Line 1291:
		rewrite!("neg-to-xor"; "(xor ?x const_-1)" => "(neg ?x)"),
		// Abs rule on 1541

		// Line 1790: -- possibly useful?

		// Other standard rules:

		//rewrite!("commute-add"; "(add ?x ?y)" => "(add ?y ?x)"),
		//rewrite!("commute-mul"; "(mul ?x ?y)" => "(mul ?y ?x)"),

		// Constnat folding rules
		rewrite!("add-0"; "(add ?x 0)" => "?x"),
		rewrite!("mul-0"; "(mul ?x 0)" => "0"),
		rewrite!("mul-1"; "(mul ?x 1)" => "?x"),
	]
}