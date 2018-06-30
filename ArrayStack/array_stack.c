#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_stack.h"

#define MIN_CAPACITY 10

static bool resize(ArrayStack *asp);

ArrayStack *createArrayStack() {
    ArrayStack *asp = malloc(sizeof(ArrayStack));
    if (!asp) return NULL;

    asp->length = 0;
    asp->capacity = MIN_CAPACITY;
    asp->elems = (int *)malloc(asp->capacity * sizeof(int));
    if (!asp->elems) return NULL;

    return asp;
}

size_t size(ArrayStack *asp) {
    return asp->length;
}

bool get(ArrayStack *asp, size_t i, int *x) {
    if (i < 0 || i >= asp->length) return false;

    *x = *(asp->elems + i);
    return true;
}

bool set(ArrayStack *asp, size_t i, int x) {
    if (i < 0 || i >= asp->length) return false;

    *(asp->elems + i) = x;
    return true;
}

bool insert(ArrayStack *asp, size_t i, int x) {
    if (i < 0 || i > asp->length) return false;

    if (asp->length == asp->capacity) {
        bool result = resize(asp);
        if (!result) return false;
    }

    size_t j = asp->length - 1;
    while (j >= i && j < asp->length) { // second condition ensures overflow doesn't cause segfault
        *(asp->elems + j + 1) = *(asp->elems + j);
        j--;
    }

    *(asp->elems + i) = x;
    asp->length++;
    return true;
}

bool removeAt(ArrayStack *asp, size_t i, int *x) {
    if (i < 0 || i >= asp->length) return false;

    *x = *(asp->elems + i);
    for (int j = i; j < asp->length; j++) *(asp->elems + j) = *(asp->elems + j + 1);
    asp->length--;

    // The asp->length > 0 check below ensures that we are never
    //   working with a backing array that has capacity zero
    //   as would otherwise be created if all elems in <*asp> were
    //   removed
    // Not putting this check in place would have caused a runtime error
    //   on the next call to insert, since new_arr would have capacity 0
    if (asp->capacity > MIN_CAPACITY && asp->capacity >= asp->length * 3) resize(asp);

    return true;
}

bool push(ArrayStack *asp, int x) {
    return insert(asp, asp->length, x);
}

bool pop(ArrayStack *asp, int *x) {
    return removeAt(asp, asp->length - 1, x);
}

void print(ArrayStack *asp) {
    printf("[");
    for (int i = 0; i < asp->length; i++) printf(" %d ", asp->elems[i]);
    printf("] L:%lu C:%lu", asp->length, asp->capacity);
    printf("\n");
}

// "private" helper functions
static size_t max(size_t a, size_t b) {
    return a > b ? a : b;
}

static bool resize(ArrayStack *asp) {
    asp->capacity = max(MIN_CAPACITY, asp->length * 2);
    int *new_arr = (int *)malloc(asp->capacity * sizeof(int));
    if (!new_arr) return false;

    for (int i = 0; i < asp->length; i++) *(new_arr + i) = *(asp->elems + i);
    free(asp->elems);

    asp->elems = new_arr;
    return true;
}
