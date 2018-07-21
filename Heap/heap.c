#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

#define MIN_CAPACITY 10

static size_t max(size_t a, size_t b);
static bool resize(Heap *hp);
static size_t parentIdx(size_t i);
static bool swap(int *elems, size_t n, size_t i, size_t j);
static bool bubbleUp(Heap *hp, size_t i);
static bool bubbleDown(Heap *hp, size_t i);

Heap *createHeap() {
    Heap *hp = malloc(sizeof(Heap));
    if (!hp) return NULL;

    hp->length = 0;
    hp->capacity = MIN_CAPACITY;
    hp->elems = malloc(hp->capacity * sizeof(int));
    if (!hp->elems) return NULL;

    return hp;
}

bool insert(Heap *hp, int x) {
    if (hp->length == hp->capacity && !resize(hp)) return false;

    hp->elems[hp->length] = x;
    hp->length++;
    return bubbleUp(hp, hp->length - 1);
}

bool getMax(Heap *hp, int *x) {
    if (hp->length == 0) return false;

    *x = hp->elems[0];
    return true;
}

bool removeMax(Heap *hp, int *x) {
    if (hp->length == 0) return false;

    *x = hp->elems[0];
    hp->elems[0] = hp->elems[--hp->length];

    if (hp->capacity > MIN_CAPACITY && hp->capacity >= hp->length * 3) resize(hp);

    return bubbleDown(hp, 0);
}

void print(Heap *hp) {
    printf("[");
    for (size_t i = 0; i < hp->length; i++) printf(" %d ", hp->elems[i]);
    printf("] L:%lu C:%lu\n", hp->length, hp->capacity);
}

// helper functions
static size_t max(size_t a, size_t b) {
    return a >= b ? a : b;
}

static bool resize(Heap *hp) {
    hp->capacity = max(MIN_CAPACITY, hp->length * 2);

    int *new_elems = malloc(hp->capacity * sizeof(int));
    if (!new_elems) return false;

    for (size_t i = 0; i < hp->length; i++) *(new_elems + i) = *(hp->elems + i);
    free(hp->elems);
    hp->elems = new_elems;
    return true;
}

static size_t parentIdx(size_t i) {
    if (i == 0) return 0;
    else return (i - 1) / 2;
}

static bool swap(int *elems, size_t n, size_t i, size_t j) {
    if (i < 0 || i >= n || j < 0 || j >= n) return false;

    int tmp = *(elems + i);
    *(elems + i) = *(elems + j);
    *(elems + j) = tmp;
    return true;
}

static bool bubbleUp(Heap *hp, size_t i) {
    if (i < 0 || i >= hp->length) return false;

    size_t j = parentIdx(i);
    while (i != 0 && hp->elems[i] > hp->elems[j]) {
        swap(hp->elems, hp->length, i, j);
        i = j;
        j = parentIdx(i);
    }
    return true;
}

static bool bubbleDown(Heap *hp, size_t i) {
    size_t lc_idx, rc_idx, next_idx;

    while (true) {
        lc_idx = 2 * i + 1;
        rc_idx = 2 * i + 2;

        if (lc_idx >= hp->length) /* no children */ next_idx = 0;
        else if (rc_idx >= hp->length) /* one child */ next_idx = lc_idx;
        else next_idx = hp->elems[lc_idx] >= hp->elems[rc_idx] ? lc_idx : rc_idx;

        if (next_idx == 0 || hp->elems[i] >= hp->elems[next_idx]) {
            break;
        } else {
            swap(hp->elems, hp->length, i, next_idx);
            i = next_idx;
        }
    }
    return true;
}
