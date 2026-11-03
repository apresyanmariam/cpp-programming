SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    
    SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
    if(position == 0){
        new_node->next = llist;
        return new_node;
    }
    SinglyLinkedListNode* current = llist;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return llist;
    
    
}