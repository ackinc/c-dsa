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
    size_t elem_size;
} LinkedList;

LinkedList createLinkedList(size_t elem_size);
size_t length(LinkedList l);
bool empty(LinkedList l);

bool insertAt(LinkedList *l, size_t pos, void *data);
bool removeAt(LinkedList *l, size_t pos);

bool insertHead(LinkedList *l, void *data);
bool insertTail(LinkedList *l, void *data);
bool removeHead(LinkedList *l);
bool removeTail(LinkedList *l);

ListElement *find(LinkedList l, void *data, bool (*cmpFn) (void *, void *));
long int findIndex(LinkedList l, void *data, bool (*cmpFn) (void *, void *));

void printList (LinkedList l, void (*printElem) (void *));

#endif
