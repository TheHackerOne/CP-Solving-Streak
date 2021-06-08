void extendLL(Node *head) {
    Node *curr = head;
    Node *forw = NULL;
    while (curr != NULL) {
        forw = curr -> next;
        Node *newNode = new Node(curr -> adta);
        curr -> next = newNode;
        newNode -> next = forw;
        curr = forw;
    }
}

void assignRandomPointers(Node *head) {
    Node *curr = head;
    Node *cran = NULL;
    while (curr != NULL) {
        cran = curr -> random;
        if (cran == NULL) {
            curr -> next -> random = NULL;
        } else
            curr -> next -> random = cran -> next;

        curr = curr -> next -> next;
    }
}

Node *extractnewLL(Node *head) {
    Node *dummy = new Node(-1);
    Node *curr = head;
    Node *prev = dummy;
    while (curr != NULL) {
        prev -> next = curr -> next;
        curr -> next = curr -> next -> next;
        prev = prev -> next;
        curr = curr -> next;
    }
    return dummy -> next;
}

Node *copyRandomList(Node *head)
{
    extendLL(head);
    assignRandomPointers(head);
    Node *nHead = extractnewLL(head);
    return nHead;
}