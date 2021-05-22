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

void printLL(Node *head) {
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

Node *mergeSortedLL(Node *head1, Node *head2) {
    Node *dummy = new Node(-1);
    Node *p = dummy;
    Node *c1 = head1;
    Node *c2 = head2;
    while (c1 != NULL && c2 != NULL) {
        if (c1 -> data < c2 -> data) {
            p -> next = c1;
            c1 = c1 -> next;
        } else {
            p -> next = c2;
            c2 = c2 -> next;
        }
        p = p -> next;
    }
    p -> next = c1 != NULL ? c1 : c2;

    return dummy -> next;
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
    cin >> n;

    Node *head1 = NULL;
    Node *temp1 = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        Node *newNode = new Node(data);
        if (head1 == NULL) {
            head1 = newNode;
            temp1 = head1;
        } else {
            temp1 -> next = newNode;
            temp1 = temp1 -> next;
        }
    }

    printLL(head);
    cout << endl;
    printLL(head1);
    cout << endl;
    Node *newHead = mergeSortedLL(head, head1);
    printLL(newHead);
    cout << endl;


    return 0;
}