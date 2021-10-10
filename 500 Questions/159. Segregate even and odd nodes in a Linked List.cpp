#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    Node* divide(int N, Node *head) {
        Node *e = new Node(-1);
        Node *o = new Node(-1);
        Node *pe = e, *po = o;
        Node *curr = head;
        while (curr != nullptr) {
            if (curr -> data % 2) {
                po -> next = curr;
                po = curr;
            } else {
                pe -> next = curr;
                pe = curr;
            }
            curr = curr -> next;
        }
        pe -> next = nullptr;
        po -> next = nullptr;
        if (e -> next == nullptr) return o -> next;
        else if (o -> next == nullptr) return e -> next;
        pe -> next = o -> next;
        return e -> next;
    }
};

int main() {


    return 0;
}