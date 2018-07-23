#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

void sortTest(void (*sortFn)(int *, size_t));
void printArr(int *elems, size_t n, bool print_nl);

void main () {
    printf("Bubble sort test\n");
    sortTest(bubbleSort);


    printf("Selection sort test\n");
    sortTest(selectionSort);

    printf("Insertion sort test\n");
    sortTest(insertionSort);

    printf("Merge sort test\n");
    sortTest(mergeSort);

    printf("Quick sort test\n");
    sortTest(quickSort);

    printf("Heap sort test\n");
    sortTest(heapSort);
}

void printArr(int *elems, size_t n, bool print_nl) {
    printf("[");
    for (size_t i = 0; i < n; i++) printf(" %d ", elems[i]);
    printf("]");
    if (print_nl) printf("\n");
}

void sortTest(void (*sortFn)(int *, size_t)) {
    size_t n = 20;
    int elems[n];

    for (size_t i = 0; i < n; i++) elems[i] = rand() % 1000;

    printArr(elems, n, false);
    printf(" Sorted: %d\n", isSorted(elems, n));

    sortFn(elems, n);

    printArr(elems, n, false);
    printf(" Sorted: %d\n", isSorted(elems, n));
}
