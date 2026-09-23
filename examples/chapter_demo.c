#include <stdio.h>

#include "dijkstra.h"
#include "dp.h"
#include "heap.h"
#include "segment_tree.h"

int main(void) {
    printf("Fibonacci(15) = %lld\n", fibonacci_memo(15));

    MinHeap *heap = heap_create(4);
    heap_push(heap, 9);
    heap_push(heap, 2);
    heap_push(heap, 7);
    int smallest = 0;
    heap_pop(heap, &smallest);
    printf("heap minimum = %d\n", smallest);
    heap_destroy(heap);

    int values[] = {4, 1, 9, 3, 7};
    SegmentTree *tree = segment_tree_build(values, 5);
    printf("max on [1, 4) = %d\n", segment_tree_query_max(tree, 1, 4));
    segment_tree_destroy(tree);

    return 0;
}
