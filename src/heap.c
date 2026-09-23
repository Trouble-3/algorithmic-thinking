#include "heap.h"

#include <stdlib.h>

struct MinHeap {
    int *data;
    size_t size;
    size_t capacity;
};

static void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

static void sift_up(MinHeap *heap, size_t i) {
    while (i > 0) {
        size_t parent = (i - 1) / 2;
        if (heap->data[parent] <= heap->data[i]) break;
        swap(&heap->data[parent], &heap->data[i]);
        i = parent;
    }
}

static void sift_down(MinHeap *heap, size_t i) {
    while (1) {
        size_t left = 2 * i + 1, right = left + 1, smallest = i;
        if (left < heap->size && heap->data[left] < heap->data[smallest]) smallest = left;
        if (right < heap->size && heap->data[right] < heap->data[smallest]) smallest = right;
        if (smallest == i) break;
        swap(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }
}

MinHeap *heap_create(size_t capacity) {
    if (capacity == 0) capacity = 8;
    MinHeap *heap = calloc(1, sizeof(*heap));
    if (!heap) return NULL;
    heap->data = malloc(capacity * sizeof(*heap->data));
    if (!heap->data) {
        free(heap);
        return NULL;
    }
    heap->capacity = capacity;
    return heap;
}

void heap_destroy(MinHeap *heap) {
    if (!heap) return;
    free(heap->data);
    free(heap);
}

int heap_push(MinHeap *heap, int value) {
    if (!heap) return 0;
    if (heap->size == heap->capacity) {
        size_t new_capacity = heap->capacity * 2;
        int *new_data = realloc(heap->data, new_capacity * sizeof(*new_data));
        if (!new_data) return 0;
        heap->data = new_data;
        heap->capacity = new_capacity;
    }
    heap->data[heap->size] = value;
    sift_up(heap, heap->size);
    ++heap->size;
    return 1;
}

int heap_pop(MinHeap *heap, int *value) {
    if (!heap || heap->size == 0 || !value) return 0;
    *value = heap->data[0];
    --heap->size;
    if (heap->size) {
        heap->data[0] = heap->data[heap->size];
        sift_down(heap, 0);
    }
    return 1;
}

size_t heap_size(const MinHeap *heap) {
    return heap ? heap->size : 0;
}
