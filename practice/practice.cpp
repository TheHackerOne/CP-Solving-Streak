class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *curr = head, *forw = nullptr;
        
        while(curr){
            forw = curr->next;
            Node *node = new Node(curr->val);
            curr->next = node;
            node->next = forw;
            curr = forw;
        }
        
        curr = head;
        Node*oh = head->next;
        while(curr){
            forw = curr->next;
            curr->next = forw->next;
            forw->random = curr->random->next;
            forw->next = forw->next->next;
            curr = curr->next;
        }
        return oh;
    }
};