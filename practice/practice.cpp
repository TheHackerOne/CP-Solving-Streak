midOfLL(Node *head){
    Node *slow = head, *fast = head;
    while(fast->next != nullptr and fast->next->next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}