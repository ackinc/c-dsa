// Binary MaxHeap implementation

#ifndef __HEAP_H_
#define __HEAP_H_

#include <stdbool.h>

typedef struct Heap {
    size_t length;
    size_t capacity;
    int *elems;
} Heap;

Heap *createHeap();
bool insert(Heap *hp, int x);
bool getMax(Heap *hp, int *x);
bool removeMax(Heap *hp, int *x);

void print(Heap *hp);

#endif
