#
# ======================================================================
# CMakeLists.txt
# ======================================================================
# CMakeLists for mapper pass.
#
# Author : Cheng Tan
#  Date : July 16, 2019
#

set(CMAKE_BUILD_TYPE Release)

list(APPEND local_sources
    DFGNode.h
    DFGNode.cpp
    DFGEdge.h
    DFGEdge.cpp
    DFG.h
    DFG.cpp
    CGRANode.h
    CGRANode.cpp
    CGRALink.h
    CGRALink.cpp
    CGRA.h
    CGRA.cpp
    Mapper.h
    Mapper.cpp
	MapResult.h
	MapResult.cpp
	Rewriter.cpp
	RustTypes.h
	RustTypes.cpp
	RustConversion.cpp
	RustConversion.h
	Options.h
	Options.cpp
    MapAlgorithms.h
    MapAlgorithms.cpp
)

add_library(mapperPass MODULE
    # List your source files here.
    mapperPass.cpp
    ${local_sources}
)

add_executable(dfgMapper
    mapFromDFG.cpp
    ${local_sources}
)

# Only needed for the standalone executbale because
# the mapperPass is intended to be loaded into opt, which
# will provide this.
llvm_map_components_to_libnames(llvm_libs support core irreader all)
target_link_libraries(dfgMapper ${llvm_libs})

# Use C++11 to compile our pass (i.e., supply -std=c++11).
#if (NOT CMAKE_VERSION VERSION_LESS 3.1)
#  target_compile_features(mapperPass PRIVATE cxx_range_for cxx_auto_type)
#endif ()

# LLVM is (typically) built with no C++ RTTI. We need to match that;
# otherwise, we'll get linker errors about missing RTTI data.
set_target_properties(mapperPass PROPERTIES
    COMPILE_FLAGS "-fno-rtti"
)
set_target_properties(dfgMapper PROPERTIES
    COMPILE_FLAGS "-fno-rtti -DDISABLE_LLVM_CMDLINE"
)

target_link_libraries(mapperPass ${CMAKE_CURRENT_SOURCE_DIR}/../CGRA-Mapper-Rust/target/release/libEggLib.so)
target_link_libraries(dfgMapper ${CMAKE_CURRENT_SOURCE_DIR}/../CGRA-Mapper-Rust/target/release/libEggLib.so)

# Get proper shared-library behavior (where symbols are not necessarily
# resolved when the shared library is linked) on OS X.
if(APPLE)
    set_target_properties(mapperPass PROPERTIES
        LINK_FLAGS "-undefined dynamic_lookup"
    )
endif(APPLE)
