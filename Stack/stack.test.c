#include <stdio.h>

#include "stack.h"

void main () {
    Stack s = createStack(sizeof(int));

    int x = 1, y = 2, z = 3, result;

    push(&s, &x);
    peek(&s, &result);
    printf("%d\n", result); // 1

    push(&s, &y);
    peek(&s, &result);
    printf("%d\n", result); // 2

    pop(&s, &result);
    printf("%d\n", result); // 2

    push(&s, &z);
    peek(&s, &result);
    printf("%d\n", result); // 3
}
