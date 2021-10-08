class Solution
{
public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head)
    {
        unordered_set<int> s;
        Node *dummy = new Node(-1);
        Node *curr = head, *prev = dummy;
        while (curr != nullptr) {
            if (s.find(curr->data) == s.end()) {
                prev -> next = curr;
                prev = curr;
                s.insert(curr -> data);
            }
            curr = curr -> next;
        }
        prev -> next = nullptr;
        return dummy -> next;
    }
};