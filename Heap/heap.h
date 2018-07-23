// Binary Heap implementation

#ifndef __HEAP_H_
#define __HEAP_H_

#include <stdbool.h>

typedef struct Heap {
    size_t length;
    size_t capacity;
    int *elems;

    // cmpFn should return:
    // -ve number if a should be placed above b
    // 0 if a and b are equal
    // +ve number if a should be placed below b
    int (*cmpFn)(int a, int b);
} Heap;

Heap *createHeap();
Heap *createHeapWithCustomCmpFn(int (*cmpFn)(int, int));
Heap *heapify(int *elems, size_t n);
Heap *heapifyWithCustomCmpFn(int *elems, size_t n, int (*cmpFn)(int, int));
bool insert(Heap *hp, int x);
bool getRoot(Heap *hp, int *x);
bool removeRoot(Heap *hp, int *x);
bool removeAt(Heap *hp, size_t idx, int *x);
size_t size(Heap *hp);

void print(Heap *hp);

#endif
