#include <stdio.h>
#include <string.h>

#include "linked_list.h"

static ListElement *createListElement (void *data, size_t elem_size);
static void deleteListElement (ListElement *elemp);

LinkedList createLinkedList (size_t size) {
    LinkedList l;
    l.head = NULL;
    l.tail = NULL;
    l.elem_size = size;
    return l;
}

size_t length (LinkedList l) {
    ListElement *cur = l.head;
    size_t n = 0;

    while (cur) {
        n++;
        cur = cur->next;
    }

    return n;
}

bool empty (LinkedList l) {
    return l.head == NULL;
}

// inserts a new elem into l by walking down l until the elem after
//   which new elem should be added
bool insertAt(LinkedList *l, size_t pos, void *data) {
    ListElement *elemp = createListElement(data, l->elem_size);
    if (!elemp) return false;

    if (pos == 0) {
        elemp->next = l->head;
        l->head = elemp;

        if (!l->tail) l->tail = elemp;
    } else {
        // cur points to the element *after* which elemp should be added
        ListElement *cur = l->head;
        while (cur && pos > 1) cur = cur->next, pos--;
        if (!cur) return false;

        elemp->next = cur->next;
        cur->next = elemp;

        if (!elemp->next) l->tail = elemp;
    }

    return true;
}

bool insertHead(LinkedList *l, void *data) {
    insertAt(l, 0, data);
}

bool insertTail(LinkedList *l, void *data) {
    ListElement *elemp = createListElement(data, l->elem_size);
    if (!elemp) return false;

    if (empty(*l)) {
        l->head = l->tail = elemp;
    } else {
        l->tail->next = elemp;
        l->tail = elemp;
    }

    return true;
}

bool removeAt(LinkedList *l, size_t pos) {
    if (empty(*l)) return false;

    ListElement *toDelete;

    if (pos == 0) {
        toDelete = l->head;
        l->head = toDelete->next;
        if (!l->head) l->tail = l->head; // deleting the only elem in the list

        deleteListElement(toDelete);
        return true;
    }

    // cur points to the element *before* the one that has to be removed
    ListElement *cur = l->head;
    while (cur && pos > 1) cur = cur->next, pos--;
    if (!cur || !cur->next) return false;

    toDelete = cur->next;
    cur->next = toDelete->next;
    if (l->tail == toDelete) l->tail = cur; // deleting the tail
    deleteListElement(toDelete);
    return true;
}

bool removeHead(LinkedList *l) {
    removeAt(l, 0);
}

bool removeTail(LinkedList *l) {
    removeAt(l, length(*l) - 1);
}

ListElement *find(LinkedList l, void *data, bool (*cmpFn) (void *, void *)) {
    ListElement *cur = l.head;
    while (cur) {
        if (cmpFn(cur->data, data) == true) break;
        cur = cur->next;
    }
    return cur;
}

// returns -1 if data not found in list
long int findIndex(LinkedList l, void *data, bool (*cmpFn) (void *, void *)) {
    long int n = 0;
    ListElement *cur = l.head;
    while (cur && !cmpFn(cur->data, data)) cur = cur->next, n++;

    if (!cur) return -1;
    else return n;
}

void printList (LinkedList l, void (*printElem) (void *)) {
    printf("[ ");
    ListElement *cur = l.head;
    while (cur) {
        printElem(cur->data);
        printf(" ");
        cur = cur->next;
    }
    printf("]\n");
}


// "private" helper functions
static ListElement *createListElement (void *data, size_t elem_size) {
    ListElement *elemp = (ListElement *)malloc(sizeof(ListElement));
    if (!elemp) return NULL;

    elemp->data = malloc(elem_size);
    if (!elemp->data) return NULL;

    memcpy(elemp->data, data, elem_size);
    elemp->next = NULL;

    return elemp;
}

static void deleteListElement (ListElement *elemp) {
    free(elemp->data);
    free(elemp);
}
