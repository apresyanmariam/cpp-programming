
//run through each node then go back to the next list's head. 

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* first = head1;
    SinglyLinkedListNode* second = head2;
    
    while(first != second){
        if(first == NULL) first = head2;
        else first = first->next;
        if(second == NULL) second = head1;
        else second = second->next;
    }
    return first->data;
    

}