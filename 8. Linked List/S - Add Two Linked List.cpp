#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

Node *reverseLL(Node *head) {
    Node *prev = nullptr;
    Node *curr = head;
    Node *forw = nullptr;
    while (curr != nullptr) {
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}

Node *addTwoNumbers(Node *l1, Node *l2)
{
    if (l1 == nullptr || l2 == nullptr) return l1 != nullptr ? l1 : l2;
    Node *c1 = reverseLL(l1);
    Node *c2 = reverseLL(l2);
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    int carry = 0;
    while (c1 != nullptr || c2 != nullptr || carry != 0) {
        int sum = (c1 != nullptr ? c1 -> data : 0) + (c2 != nullptr ? c2 -> data : 0) + carry;
        int digit = sum % 10;
        carry = sum / 10;
        prev -> next = new Node(digit);
        prev = prev -> next;
        if (c1 != nullptr) c1 = c1 -> next;
        if (c2 != nullptr) c2 = c2 -> next;
    }
    Node *nHead = reverseLL(dummy -> next);
    return nHead;
}

void printll(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    Node *head = nullptr;
    Node *temp = nullptr;
    for (int i = 1; i <= n; i++) {
        int data;
        cin >> data;
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            temp = newNode;
        } else {
            temp -> next = newNode;
            temp = temp -> next;
        }
    }

    Node *head1 = nullptr;
    Node *temp1 = nullptr;
    for (int i = 1; i <= m; i++) {
        int data;
        cin >> data;
        Node *newNode = new Node(data);
        if (head1 == nullptr) {
            head1 = newNode;
            temp1 = newNode;
        } else {
            temp1 -> next = newNode;
            temp1 = temp1 -> next;
        }
    }

    printll(head);
    printll(head1);
    Node *nHead = addTwoNumbers(head, head1);
    printll(nHead);

    return 0;
}