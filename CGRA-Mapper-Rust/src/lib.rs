#[repr(C)]
pub struct CPPNode {
	op: *const u8,

	num_children: i32,
	child_ids: *const i32
}


type CppDFG = *const CPPNode;

#[no_mangle]
pub extern fn optimize_with_egraphs(input: CppDFG) -> *const CppDFG
{
	panic!()
}
