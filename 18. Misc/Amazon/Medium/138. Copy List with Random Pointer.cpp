/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node *h1 = head, *curr = nullptr, *forw = nullptr;
        while(h1 != nullptr){
            curr = h1;
            forw = h1 -> next;
            Node *newNode = new Node(curr -> val);
            curr -> next = newNode;
            newNode -> next = forw;
            h1 = forw;
        }
        
        curr = head;
        while(curr != nullptr){
            if(curr -> random != nullptr)
                curr -> next -> random = curr -> random -> next;
            curr = curr -> next -> next;
        }
        
        Node *newList = head -> next, *oldList = head;
        Node *currNew = head -> next, *currOld = head;
        
        while(currNew -> next != nullptr and currOld -> next != nullptr){
            currOld -> next = currOld -> next -> next;
            currNew -> next = currNew -> next -> next;
            currNew = currNew -> next;
            currOld = currOld -> next;
        }
        
        currNew -> next = currOld -> next = nullptr;
        
        return newList;
    }
};