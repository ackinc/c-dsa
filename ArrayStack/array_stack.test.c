#include <stdbool.h>
#include <stdio.h>

#include "array_stack.h"

int main () {
    ArrayStack *asp = createArrayStack();
    if (!asp) {
        printf("ERROR: Failed to allocate memory for arraystack");
        return 1;
    }

    printf("Empty arraystack\n");
    print(asp);

    push(asp, 4);
    push(asp, 8);
    push(asp, 0);
    printf("Pushed 3 elems\n");
    print(asp);

    int x;

    pop(asp, &x);
    printf("Popped one elem\n");
    printf("Popped value: %d\n", x);
    print(asp);

    printf("Pushing 10 elems to trigger resize\n");
    for (int i = 0; i < 10; i++) push(asp, i + 11);
    print(asp);

    printf("Removing 6 elems to trigger another resize\n");
    for (int i = 0; i < 6; i++) removeAt(asp, 3, &x);
    print(asp);

    printf("Removing 2 elems to trigger another resize, to min capacity\n");
    for (int i = 0; i < 2; i++) removeAt(asp, 2, &x);
    print(asp);

    printf("Removing another element, but this won't trigger a resize\n");
    removeAt(asp, 2, &x);
    printf("Element removed: %d\n", x);
    print(asp);

    printf("Inserting an element at the head of the arraystack\n");
    insert(asp, 0, 10);
    print(asp);

    return 0;
}
