#ifndef HASH_SET_H
#define HASH_SET_H

#include <stddef.h>

typedef struct HashSet HashSet;

HashSet *hash_set_create(size_t bucket_count);
void hash_set_destroy(HashSet *set);
int hash_set_insert(HashSet *set, int key);
int hash_set_contains(const HashSet *set, int key);

#endif
