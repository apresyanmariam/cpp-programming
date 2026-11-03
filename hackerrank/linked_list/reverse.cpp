// DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
//     DoublyLinkedListNode* current = llist;
//     DoublyLinkedListNode* temp = nullptr;

//     while (current != nullptr) {
//         temp = current->prev;
//         current->prev = current->next;
//         current->next = temp;
//         current = current->prev;
//     }

//     if (temp != nullptr) {
//         llist = temp->prev;
//     }

//     return llist;
    
// }

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* current = llist;
    DoublyLinkedListNode* prev = nullptr;

    while (current != nullptr) {
        DoublyLinkedListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }


    return llist;
    
}

