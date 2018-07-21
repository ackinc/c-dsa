// Binary MaxHeap implementation

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
bool insert(Heap *hp, int x);
bool getMax(Heap *hp, int *x);
bool removeMax(Heap *hp, int *x);

void print(Heap *hp);

#endif
