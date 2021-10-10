bool isCircular(Node *head)
{
    Node *temp = head -> next;
    while (temp != nullptr) {
        if (temp == head) return true;
        temp = temp -> next;
    }
    return false;
}