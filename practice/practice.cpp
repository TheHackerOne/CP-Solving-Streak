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

    ~Node() {
        delete next;
    }
};

Node *reverseLL(Node *head) {
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

Node *midElement(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printLL(Node *head) {
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

void fold(Node *head) {
    Node *mid = midElement(head);
    Node *nHead = reverseLL(mid -> next);
    mid -> next = NULL;

    Node *h1 = head;
    Node *h2 = nHead;
    Node *f1 = NULL;
    Node *f2 = NULL;

    while (h2 != NULL) {
        f1 = h1 -> next;
        f2 = h2 -> next;
        h1 -> next = h2;
        h2 -> next = f1;
        h1 = f1;
        h2 = f2;
    }
}

void unfold(Node *head) {
    Node *h1 = head;
    Node *h2 = head -> next;
    Node *p1 = head;
    Node *p2 = head -> next;
    while (p2 != NULL && p2 -> next != NULL) {
        Node *f = p2 -> next;
        p1 -> next = f;
        p2 -> next = f -> next;
        p1 = f;
        p2 = f -> next;
    }
    p1 -> next = NULL;
    Node *nHead = reverseLL(h2);
    p1 -> next = nHead;
}

int main() {
    int n;
    cin >> n;

    Node *head = NULL;
    Node *temp = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp -> next = newNode;
            temp = temp -> next;
        }
    }
    cout << "Initial LL -> ";
    printLL(head);
    cout << endl;
    fold(head);
    cout << "LL after folding -> ";
    printLL(head);
    unfold(head);
    cout << endl;
    cout << "LL after unfolding -> ";
    printLL(head);

    delete head;

    return 0;
}