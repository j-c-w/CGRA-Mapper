cmake_minimum_required(VERSION 3.1)
project(cgramapper CXX)

#if(POLICY CMP0025)
#  cmake_policy(SET CMP0025 NEW)
#endif()

find_package(LLVM REQUIRED CONFIG)
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})

add_custom_command (
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/CGRA-Mapper-Rust/target/release/libEggLib.so
	DEPENDS CGRA-Mapper-Rust/src
	COMMAND make
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/CGRA-Mapper-Rust/
)

# configure_file (
# 	${CMAKE_SOURCE_DIR}/CGRA-Mapper-Rust/target/release/libEggLib.so ${CMAKE_CURRENT_BINARY_DIR}/CGRA-Mapper-Rust/target/release/libEggLib.so
# )

add_library(eggLib SHARED ${CMAKE_CURRENT_BINARY_DIR}/CGRA-Mapper-Rust/target/release/libEggLib.so)
set_target_properties(eggLib PROPERTIES LINKER_LANGUAGE CXX)

#set_property(TARGET eggLib PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/CGRA-Mapper-Rust/target/release/libEggLib.so)

add_subdirectory(src)  # Use your pass directory here.
