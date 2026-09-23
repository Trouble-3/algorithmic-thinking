cmake_minimum_required(VERSION 3.16)
project(algorithmic_thinking C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(algorithms
    src/binary_search.c
    src/dijkstra.c
    src/dp.c
    src/graph.c
    src/hash_set.c
    src/heap.c
    src/segment_tree.c
    src/tree.c
    src/union_find.c
)

target_include_directories(algorithms PUBLIC include)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(algorithms PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(algorithmic_thinking_tests tests/test_all.c)
target_link_libraries(algorithmic_thinking_tests PRIVATE algorithms)

enable_testing()
add_test(NAME algorithmic_thinking_tests COMMAND algorithmic_thinking_tests)

add_executable(algorithmic_thinking_demo examples/demo.c)
target_link_libraries(algorithmic_thinking_demo PRIVATE algorithms)
