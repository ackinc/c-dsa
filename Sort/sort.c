#include <stdbool.h>
#include <stdlib.h> // rand()
#include <math.h> // floor

#include "../Heap/heap.h"
#include "sort.h"

static void swap(int *elems, size_t i, size_t j);
static bool mergeSortHelper(int *elems, size_t l, size_t r);
static bool merge(int *elems, size_t l, size_t m, size_t r);
static void quickSortHelper(int *elems, size_t l, size_t r);
static size_t partition(int *elems, size_t l, size_t r);


bool isSorted(int *elems, size_t n) {
    for (size_t i = 1; i < n; i++) if (elems[i] < elems[i - 1]) return false;
    return true;
}

void bubbleSort(int *elems, size_t n) {
    size_t i, j, n_swaps;
    while (true) {
        n_swaps = 0;
        for (i = 0, j = 1; j < n; i++, j++) {
            if (elems[i] > elems[j]) {
                swap(elems, i, j);
                n_swaps++;
            }
        }
        if (n_swaps == 0) break;
    }
}

void selectionSort(int *elems, size_t n) {
    if (n <= 1) return;

    size_t min_idx;
    int min;
    for (size_t i = 0; i < n - 1; i++) {
        min_idx = i, min = elems[i];
        for (size_t j = i + 1; j < n; j++) {
            if (elems[j] < min) min_idx = j, min = elems[j];
        }
        if (min_idx != i) swap(elems, i, min_idx);
    }
}

void insertionSort(int *elems, size_t n) {
    if (n <= 1) return;

    size_t i, j;
    for (i = 1; i < n; i++) {
        j = i;
        while (j > 0 && elems[j] < elems[j - 1]) {
            swap(elems, j, j - 1);
            j--;
        }
    }
}

void mergeSort(int *elems, size_t n) {
    if (n <= 1) return;
    else mergeSortHelper(elems, 0, n - 1);
}

void quickSort(int *elems, size_t n) {
    if (n <= 1) return;
    quickSortHelper(elems, 0, n - 1);
}

void heapSort(int *elems, size_t n) {
    Heap *hp = heapify(elems, n);

    int x;
    for (size_t i = 0; i < n; i++) removeRoot(hp, elems + i);
}


// static helper functions
static void swap(int *elems, size_t i, size_t j) {
    int tmp = elems[i];
    elems[i] = elems[j];
    elems[j] = tmp;
}

static bool mergeSortHelper(int *elems, size_t l, size_t r) {
    if (r - l < 1) return true;

    size_t mid = (l + r) / 2;
    if (!mergeSortHelper(elems, l, mid)) return false;
    if (!mergeSortHelper(elems, mid + 1, r)) return false;
    return merge(elems, l, mid, r);
}

static bool merge(int *elems, size_t l, size_t m, size_t r) {
    int *l_elems = (int *)malloc((m - l + 1) * sizeof(int));
    int *r_elems = (int *)malloc((r - m) * sizeof(int));
    if (!l_elems || !r_elems) return false;

    for (size_t i = 0; i < m - l + 1; i++) l_elems[i] = elems[i + l];
    for (size_t i = 0; i < r - m; i++) r_elems[i] = elems[i + m + 1];

    size_t i = 0, j = 0, k = l;
    while (i < m - l + 1 && j < r - m) {
        if (l_elems[i] < r_elems[j]) elems[k++] = l_elems[i++];
        else elems[k++] = r_elems[j++];
    }
    if (i == m - l + 1) while (j < r - m) elems[k++] = r_elems[j++];
    if (j == r - m) while (i < m - l + 1) elems[k++] = l_elems[i++];
    return true;
}

static void quickSortHelper(int *elems, size_t l, size_t r) {
    if (r - l < 1) return;

    // choose pivot
    size_t pivot_idx = floor(l + (rand() % (r - l + 1)));
    swap(elems, l, pivot_idx);

    pivot_idx = partition(elems, l, r);

    // recurse
    if (pivot_idx > l) quickSortHelper(elems, l, pivot_idx - 1);
    if (pivot_idx < r) quickSortHelper(elems, pivot_idx + 1, r);
}

// partitions elems[l, r] around the pivot elems[l]
// returns final index of pivot element
static size_t partition(int *elems, size_t l, size_t r) {
    // i represents boundary between elems smaller than pivot, and those larger than pivot
    //   it points to the elem that will be "swapped-out" when we encounter an elem smaller than pivot
    // j represents boundary between elems already processed, and those not yet processed
    //   it points to the elem we are about to process
    size_t i, j;
    i = j = l + 1;
    int pivot = elems[l];
    while (j <= r) {
        if (elems[j] < pivot) {
            swap(elems, i, j);
            i++;
        }
        j++;
    }
    swap(elems, l, i - 1); // puts the pivot into its rightful place
    return i - 1;
}
