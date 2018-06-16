#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct ListElement {
    void *data;
    struct ListElement *next;
} ListElement;

typedef struct LinkedList {
    ListElement *head;
    ListElement *tail;
    size_t elem_size;
} LinkedList;

LinkedList createLinkedList(size_t elem_size); // O(1)
size_t length(LinkedList l); // O(n)
bool empty(LinkedList l); // O(1)

bool insertAt(LinkedList *l, size_t pos, void *data); // O(n)
bool removeAt(LinkedList *l, size_t pos); // O(n)

bool insertHead(LinkedList *l, void *data); // O(1)
bool insertTail(LinkedList *l, void *data); // O(1)
bool removeHead(LinkedList *l); // O(1)
bool removeTail(LinkedList *l); // O(n)

ListElement *find(LinkedList l, void *data, bool (*cmpFn) (void *, void *)); // O(n)
long int findIndex(LinkedList l, void *data, bool (*cmpFn) (void *, void *)); // O(n)

void printList (LinkedList l, void (*printElem) (void *)); // O(n)

#endif
