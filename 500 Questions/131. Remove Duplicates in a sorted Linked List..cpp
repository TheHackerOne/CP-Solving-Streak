Node *removeDuplicates(Node *head)
{
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    Node *curr = head, *forw = nullptr;
    while (curr != nullptr) {
        forw = curr -> next;
        while (forw != nullptr && curr -> data == forw -> data) {
            curr = forw;
            forw = forw -> next;
        }
        curr -> next = nullptr;
        prev -> next = curr;
        prev = curr;
        curr = forw;
    }
    return dummy -> next;
}