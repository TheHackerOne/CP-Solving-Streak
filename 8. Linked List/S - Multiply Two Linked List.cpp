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

void printll(Node *head) {
    Node *t =  head;
    while (t != NULL) {
        cout << t -> data << " ";
        t = t -> next;
    }
    cout << endl;
}

Node *reversell(Node *head) {
    Node *prev = NULL;
    Node *curr = head;
    Node *forw = NULL;
    while (curr != NULL) {
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}

Node *productLL(Node *h1, int num) {
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    int carry = 0;
    while (h1 != nullptr || carry != 0) {
        int prod = ((h1 != nullptr ? h1 -> data : 0) * num) + carry;
        int digit = prod % 10;
        carry = prod / 10;
        prev -> next = new Node(digit);
        prev = prev -> next;
        if (h1 != nullptr) h1 = h1 -> next;
    }
    return dummy -> next;
}

void addTwoLL(Node *curr, Node *ans) {
    Node *c1 = curr;
    Node *c2 = ans;
    int carry = 0;
    while (c1 != nullptr) {
        int sum = c1 -> data + (c2 -> next != nullptr ? c2 -> next -> data : 0) + carry;
        int digit = sum % 10;
        carry = sum / 10;
        if (c2 -> next == NULL) {
            Node *newNode = new Node(digit);
            c2 -> next = newNode;
        } else {
            c2 -> next -> data = digit;
        }
        c2 = c2 -> next;
        c1 = c1 -> next;
    }
}

Node *multiplyTwoLL(Node *l1, Node *l2) {
    Node *c1 = reversell(l1);
    Node *c2 = reversell(l2);
    Node *temp = c2;
    Node *dummy = new Node(-1);
    Node *itr = dummy;
    while (temp != nullptr) {
        Node *prod = productLL(c1, temp -> data);
        addTwoLL(prod, itr);
        itr = itr -> next;
        temp = temp -> next;
    }
    return dummy -> next;
}

int main() {
    int n, m;
    cin >> n >> m;

    Node *head1 = NULL;
    Node *temp1 = NULL;
    for (int i = 1; i <= n; i++) {
        int data;
        cin >> data;
        Node *newNode = new Node(data);
        if (head1 == NULL) {
            head1 = newNode;
            temp1 = newNode;
        } else {
            temp1 -> next = newNode;
            temp1 = temp1 -> next;
        }
    }

    Node *head2 = NULL;
    Node *temp2 = NULL;
    for (int i = 1; i <= m; i++) {
        int data;
        cin >> data;
        Node *newNode = new Node(data);
        if (head2 == NULL) {
            head2 = newNode;
            temp2 = newNode;
        } else {
            temp2 -> next = newNode;
            temp2 = temp2 -> next;
        }
    }

    printll(head1);
    printll(head2);

    Node *nHead = multiplyTwoLL(head1, head2);
    nHead = reversell(nHead);
    printll(nHead);

    return 0;
}