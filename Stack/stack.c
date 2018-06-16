#include <stdlib.h>
#include <string.h>

#include "stack.h"

static StackElement *createStackElement(void *data, size_t size);
static void deleteStackElement(StackElement *elemp);

Stack createStack(size_t elem_size) {
    Stack s;
    s.top = NULL;
    s.elem_size = elem_size;
    return s;
}

bool empty(Stack s) {
    return s.top == NULL;
}

bool push(Stack *s, void *data) {
    StackElement *elemp = createStackElement(data, s->elem_size);
    if (!elemp) return false;

    elemp->next = s->top;
    s->top = elemp;
    return true;
}

bool pop(Stack *s, void *dest) {
    if (empty(*s)) return false;
    else {
        StackElement *topElem = s->top;
        memcpy(dest, topElem->data, s->elem_size);

        s->top = topElem->next;
        deleteStackElement(topElem);

        return true;
    }
}

bool peek(Stack *s, void *dest) {
    if (empty(*s)) return false;
    else {
        memcpy(dest, s->top->data, s->elem_size);
        return true;
    }
}


// "private" helper functions

static StackElement *createStackElement(void *data, size_t size) {
    StackElement *elemp = malloc(sizeof(StackElement));
    if (!elemp) return NULL;

    elemp->data = malloc(size);
    if (!elemp->data) return NULL;

    memcpy(elemp->data, data, size);

    elemp->next = NULL;

    return elemp;
}

static void deleteStackElement(StackElement *elemp) {
    free(elemp->data);
    free(elemp);
}
