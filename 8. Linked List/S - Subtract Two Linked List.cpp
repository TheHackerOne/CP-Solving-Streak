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

Node *reversell(Node *head) {
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

Node *subtractTwoNumbers(Node *l1, Node *l2)
{
    if (l2 == nullptr) return l1;
    if (l1 == nullptr) {
        l2 -> data = -(l2 -> data);
        return l2;
    }
    Node *c1 = reversell(l1);
    Node *c2 = reversell(l2);
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    int borrow = 0;
    while (c1 != nullptr) {
        int diff = borrow + ( c1 -> data ) - (c2 != nullptr ? c2 -> data : 0);
        if (diff < 0) {
            borrow = -1;
            diff += 10;
        } else {
            borrow = 0;
        }
        prev -> next = new Node(diff);
        prev = prev -> next;
        if (c2 != nullptr) c2 = c2 -> next;
        c1 = c1 -> next;
    }

    return reversell(dummy -> next);
}

void printll(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node *removeTrailingZeros(Node *head) {
    Node *th = head;
    while (th -> data == 0)
        th = th -> next;
    return th;
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
    Node *nHead = subtractTwoNumbers(head, head1);
    // nHead = removeTrailingZeros(nHead);
    printll(nHead);

    return 0;
}