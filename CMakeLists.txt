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

add_executable(chapter_demo examples/chapter_demo.c)
target_link_libraries(chapter_demo PRIVATE algorithms)

add_executable(solution_01_duplicate_detector solutions/01-duplicate-detector/main.c)
target_link_libraries(solution_01_duplicate_detector PRIVATE algorithms)

add_executable(solution_02_tree_aggregate solutions/02-tree-aggregate/main.c)
target_link_libraries(solution_02_tree_aggregate PRIVATE algorithms)

add_executable(solution_03_min_coins solutions/03-min-coins/main.c)
target_link_libraries(solution_03_min_coins PRIVATE algorithms)

add_executable(solution_04_bfs_distances solutions/04-bfs-distances/main.c)
target_link_libraries(solution_04_bfs_distances PRIVATE algorithms)

add_executable(solution_05_dijkstra solutions/05-dijkstra/main.c)
target_link_libraries(solution_05_dijkstra PRIVATE algorithms)

add_executable(solution_06_first_feasible solutions/06-first-feasible/main.c)
target_link_libraries(solution_06_first_feasible PRIVATE algorithms)

add_executable(solution_07_range_max solutions/07-range-max/main.c)
target_link_libraries(solution_07_range_max PRIVATE algorithms)

add_executable(solution_08_dynamic_communities solutions/08-dynamic-communities/main.c)
target_link_libraries(solution_08_dynamic_communities PRIVATE algorithms)

add_executable(algorithmic_thinking_bench benchmarks/benchmarks.c)
target_link_libraries(algorithmic_thinking_bench PRIVATE algorithms)
