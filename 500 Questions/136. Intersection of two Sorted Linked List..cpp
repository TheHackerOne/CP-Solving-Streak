#include<bits/stdc++.h>
using namespace std;

Node* findIntersection(Node* head1, Node* head2)
{
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    Node *c1 = head1, *c2 = head2;
    while (c1 != nullptr && c2 != nullptr) {
        if (c1 -> data == c2 -> data) {
            // cout<<c1 -> data<<endl;
            Node *newNode = new Node(c1 -> data);
            prev -> next = newNode;
            prev = newNode;
            c1 = c1 -> next;
            c2 = c2 -> next;
        } else if (c1 -> data > c2 -> data) {
            c2 = c2 -> next;
        } else {
            c1 = c1 -> next;
        }
    }
    prev -> next = nullptr;

    return dummy -> next;
}

int main() {


    return 0;
}