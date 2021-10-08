
// Iterative
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

// Recursive
class Solution
{
public:
    //Function to reverse a linked list.
    Node *newHead = nullptr;
    Node *recurLL(Node *node) {
        // base case
        if (node -> next == nullptr) {
            newHead = node;
            return node;
        }

        Node *ans = recurLL(node -> next);
        ans -> next = node;
        node -> next = nullptr;
        return node;
    }
    struct Node* reverseList(struct Node *head)
    {
        recurLL(head);
        return newHead;
    }
};