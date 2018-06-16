#include <stdio.h>

#include "linked_list.h"

void printInt(void *intp) {
    printf("%d", *(int *)intp);
}

bool numCmp(void *x, void *y) {
    return *(int *)x == *(int *)y;
}

void main() {
    LinkedList int_list = createLinkedList(sizeof(int));

    int x = 1, y = 2, z = 3;

    insertTail(&int_list, &x);
    insertTail(&int_list, &y);
    insertTail(&int_list, &z);
    printList(int_list, printInt); // [ 1 2 3 ]

    insertHead(&int_list, &x);
    insertHead(&int_list, &y);
    insertHead(&int_list, &z);
    printList(int_list, printInt); // [ 3 2 1 1 2 3 ]

    x = 4;
    insertAt(&int_list, 1, &x);
    printList(int_list, printInt); // [ 3 4 2 1 1 2 3 ]
    insertAt(&int_list, 4, &x);
    printList(int_list, printInt); // [ 3 4 2 1 4 1 2 3 ]

    removeHead(&int_list);
    printList(int_list, printInt); // [ 4 2 1 4 1 2 3 ]

    removeTail(&int_list);
    printList(int_list, printInt); // [ 4 2 1 4 1 2 ]

    removeAt(&int_list, 2);
    printList(int_list, printInt); // [ 4 2 4 1 2 ]

    removeAt(&int_list, 3);
    printList(int_list, printInt); // [ 4 2 4 2 ]

    printf("%d\n", (int)length(int_list)); // 4

    ListElement *elemp = find(int_list, &y, numCmp);
    printf("%d\n", *(int *)elemp->data); // 2
    printf("%ld\n", findIndex(int_list, &y, numCmp)); // 1

    int missing = 8;
    elemp = find(int_list, &missing, numCmp);
    printf("%lu\n", (unsigned long)elemp); // 0
    printf("%ld\n", findIndex(int_list, &missing, numCmp)); // -1
}
