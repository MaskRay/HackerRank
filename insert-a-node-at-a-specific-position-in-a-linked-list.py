def insertNodeAtPosition(llist, data, position):
    new_node = SinglyLinkedListNode(data)
    if position == 0:
        new_node.next = llist
        return new_node
    else:
        current = llist
        for _ in range(position - 1):
            current = current.next
        new_node.next = current.next
        current.next = new_node
        return llist
