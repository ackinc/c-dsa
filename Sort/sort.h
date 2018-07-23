#ifndef __SORT_H_
#define __SORT_H_

#include <stddef.h>
#include <stdbool.h>

bool isSorted(int *elems, size_t n);
void bubbleSort(int *elems, size_t n);
void selectionSort(int *elems, size_t n);
void insertionSort(int *elems, size_t n);
void mergeSort(int *elems, size_t n);
void quickSort(int *elems, size_t n);
void heapSort(int *elems, size_t n);

#endif
