#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

typedef struct StackElement {
    void *data;
    struct StackElement *next;
} StackElement;

typedef struct Stack {
    StackElement *top;
    size_t elem_size;
} Stack;

Stack createStack(size_t elem_size); // O(1)
bool empty(Stack s); // O(1)
bool push(Stack *s, void *data); // O(1)
bool pop(Stack *s, void *dest); // O(1)
bool peek(Stack *s, void *dest); // O(1)

#endif
