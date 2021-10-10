#include<bits/stdc++.h>
using namespace std;

Node * *middleEle(Node *head) {
    Node *slow = head, *fast = head;
    while (fast -> next != nullptr && fast -> next -> next != nullptr) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    Node * *ans = new Node*[2];
    if (fast -> next == nullptr) {
        ans[0] = slow, ans[1] = fast;
    } else {
        ans[0] = slow, ans[1] = fast -> next;
    }
    return ans;
}

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *firstEle = head;
    Node *temp = head -> next, *temp2 = nullptr;
    while (temp != firstEle) {
        temp2 = temp;
        temp = temp -> next;
    }
    temp2 -> next = nullptr;
    Node **ans = middleEle(head);
    Node *h1 = head, *t1 = ans[0], *h2 = ans[0] -> next, *t2 = ans[1];
    ans[0] -> next = nullptr;
    t1 -> next = h1;
    t2 -> next = h2;
    *head1_ref = h1;
    *head2_ref = h2;
}

int main() {


    return 0;
}