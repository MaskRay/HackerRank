def insertNodeAtTail(head, data):
    if head is None:
        return SinglyLinkedListNode(data)
    x = head
    while x.next is not None:
        x = x.next
    x.next = SinglyLinkedListNode(data)
    return head
