
//Floyd's algorithm
//fast pointer moves 2 at a time, slow moves 1 ata time. if they meet at one point there is a cycle

bool has_cycle(Node* head) {
    Node* fast = head;
    Node* slow = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
    
}