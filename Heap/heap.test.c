#include <stdio.h>

#include "heap.h"

void main () {
    Heap *hp = createHeap();

    for (int i = 0; i < 10; i++) insert(hp, i);
    printf("Inserted 10 elems\n");
    print(hp);

    int x;
    insert(hp, 100);
    getMax(hp, &x);
    printf("Inserted a maximal element: %d\n", x);
    print(hp);

    int y;
    removeMax(hp, &y);
    printf("Removed maximum element: %d\n", y);
    print(hp);
    removeMax(hp, &y);
    printf("Removed maximum element: %d\n", y);
    print(hp);
}
