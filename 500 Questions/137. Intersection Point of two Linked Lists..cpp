#include<bits/stdc++.h>
using namespace std;

int lengthLL(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != nullptr) {
        temp = temp -> next;
        count++;
    }
    return count;
}
int intersectPoint(Node* head1, Node* head2)
{
    int l1 = lengthLL(head1);
    int l2 = lengthLL(head2);
    Node *h1 = nullptr, *h2 = nullptr;
    if (l1 < l2) {
        h1 = head2;
        h2 = head1;
    } else {
        h1 = head1;
        h2 = head2;
    }
    int diff = abs(l1 - l2);
    while (diff--) {
        h1 = h1 -> next;
    }
    int count = 0, ans;
    while (h1 != h2) {
        h1 = h1 -> next;
        h2 = h2 -> next;
    }
    return h1 -> data;

}

int main() {


    return 0;
}