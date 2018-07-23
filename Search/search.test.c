#include <stddef.h> // size_t
#include <stdio.h> // printf

#include "search.h"

void printArr(int *elems, size_t n, bool print_nl);
void testBinSearch(int *elems, size_t n, int x, int y);

void main () {
    size_t n = 20;
    int elems[n];
    for (size_t i = 0; i < n; i++) elems[i] = (i + 1) * 5;

    printf("Test on non-empty array\n");
    testBinSearch(elems, n, 12, 14);
    testBinSearch(elems, n, 12, 16);
    testBinSearch(elems, n, 20, 24);
    testBinSearch(elems, n, 26, 30);
    testBinSearch(elems, n, 30, 30);
    testBinSearch(elems, n, 19, 31);

    printf("Testing extreme elems\n");
    testBinSearch(elems, n, 5, 5);
    testBinSearch(elems, n, 100, 100);

    printf("Testing for elems off the left end of array\n");
    testBinSearch(elems, n, -10, 4);
    testBinSearch(elems, n, 0, 0);

    printf("Testing for elems off the right end\n");
    testBinSearch(elems, n, 102, 108);
    testBinSearch(elems, n, 105, 105);
}

void printArr(int *elems, size_t n, bool print_nl) {
    printf("[");
    for (size_t i = 0; i < n; i++) printf(" %d ", elems[i]);
    printf("]");
    if (print_nl) printf("\n");
}

void testBinSearch(int *elems, size_t n, int x, int y) {
    bool result;
    size_t idx;

    printf("\n");

    printf("Binary search test on array: ");
    printArr(elems, n, false);
    printf(" for a number in [%d, %d]\n", x, y);

    result = binarySearch(elems, 0, n - 1, x, y, &idx);
    printf("Return value: %d\n", result);
    if (result) printf("Idx: %lu; Elem: %d\n", idx, elems[idx]);

    printf("\n");
}
