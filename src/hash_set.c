#include "hash_set.h"

#include <stdint.h>
#include <stdlib.h>

typedef struct Entry {
    int key;
    struct Entry *next;
} Entry;

struct HashSet {
    size_t bucket_count;
    Entry **buckets;
};

static size_t hash_int(int key, size_t bucket_count) {
    uint32_t x = (uint32_t)key;
    x ^= x >> 16;
    x *= 0x7feb352dU;
    x ^= x >> 15;
    return (size_t)(x % bucket_count);
}

HashSet *hash_set_create(size_t bucket_count) {
    if (bucket_count == 0) return NULL;
    HashSet *set = calloc(1, sizeof(*set));
    if (!set) return NULL;
    set->buckets = calloc(bucket_count, sizeof(*set->buckets));
    if (!set->buckets) {
        free(set);
        return NULL;
    }
    set->bucket_count = bucket_count;
    return set;
}

void hash_set_destroy(HashSet *set) {
    if (!set) return;
    for (size_t i = 0; i < set->bucket_count; ++i) {
        Entry *cur = set->buckets[i];
        while (cur) {
            Entry *next = cur->next;
            free(cur);
            cur = next;
        }
    }
    free(set->buckets);
    free(set);
}

int hash_set_contains(const HashSet *set, int key) {
    if (!set) return 0;
    size_t bucket = hash_int(key, set->bucket_count);
    for (Entry *cur = set->buckets[bucket]; cur; cur = cur->next)
        if (cur->key == key) return 1;
    return 0;
}

int hash_set_insert(HashSet *set, int key) {
    if (!set || hash_set_contains(set, key)) return 0;
    size_t bucket = hash_int(key, set->bucket_count);
    Entry *entry = malloc(sizeof(*entry));
    if (!entry) return -1;
    entry->key = key;
    entry->next = set->buckets[bucket];
    set->buckets[bucket] = entry;
    return 1;
}
