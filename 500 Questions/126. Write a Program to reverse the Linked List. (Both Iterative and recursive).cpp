class Solution
{
public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node *prev = nullptr, *curr = head, *forw = nullptr;
        while (curr != nullptr) {
            forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
};