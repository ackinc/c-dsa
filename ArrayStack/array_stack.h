/*
    An implementation of the List interface that executes Stack operations
    very efficiently
*/

#ifndef ARRAY_STACK_H_
#define ARRAY_STACK_H_

#include <stdbool.h>

typedef struct ArrayStack {
    size_t length;
    size_t capacity;
    int *elems;
} ArrayStack;

ArrayStack *createArrayStack();
size_t size(ArrayStack *asp);
bool get(ArrayStack *asp, size_t i, int *x);
bool set(ArrayStack *asp, size_t i, int x);
bool insert(ArrayStack *asp, size_t i, int x);
bool removeAt(ArrayStack *asp, size_t i, int *x);
bool push(ArrayStack *asp, int x);
bool pop(ArrayStack *asp, int *x);

void print(ArrayStack *asp);

#endif
