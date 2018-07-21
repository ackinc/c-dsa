#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

int bSubA(int a, int b) { return b - a; }

void main () {
    Heap *hp = createHeap();
    // Heap *hp = createHeapWithCustomCmpFn(bSubA);

    for (int i = 0; i < 10; i++) insert(hp, i);
    printf("Inserted 10 elems\n");
    print(hp);

    int x;
    insert(hp, 100);
    getMax(hp, &x);
    printf("Inserted a maximal element. Root: %d\n", x);
    print(hp);

    int y;
    removeMax(hp, &y);
    printf("Removed root: %d\n", y);
    print(hp);
    removeMax(hp, &y);
    printf("Removed root: %d\n", y);
    print(hp);

    int *elems = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) elems[i] = i + 50;
    Heap *hp2 = heapifyWithCustomCmpFn(elems, 10, bSubA);
    printf("Heapified a 10 element array\n");
    print(hp2);
}
