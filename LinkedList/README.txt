Adding a tail pointer improves the performance of insertTail, and getTail
Adding prevNode links improves the performance of insertBefore, remove, and removeBefore
Adding both additionally improves performance of removeTail
- Store list length as a member of the list structure will double performance of 
    functions involving index-based list traversal

TODO
1. Implementation of DoublyLinkedList and DoublyLinkedListWithTailPointer
2. Implementation of functions "insertBefore", "insertAfter", "remove", "removeBefore", "removeAfter"
