#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

typedef struct MinHeap MinHeap;

MinHeap *heap_create(size_t capacity);
void heap_destroy(MinHeap *heap);
int heap_push(MinHeap *heap, int value);
int heap_pop(MinHeap *heap, int *value);
size_t heap_size(const MinHeap *heap);

#endif
