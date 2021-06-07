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

void printLL(Node *head) {
    Node *tHead = head;
    while (tHead != NULL) {
        cout << tHead -> data << " ";
        tHead = tHead -> next;
    }
}

int countNode(Node *head) {
    Node *tHead = head;
    int count = 0;
    while (tHead != NULL) {
        tHead = tHead -> next;
        count++;
    }
    return count;
}

Node *segregateEvenOdd(Node *head)
{
    Node *oh = new Node(-1);
    Node *eh = new Node(-1);
    Node *po = oh;
    Node *pe = eh;
    Node *curr = head;
    while (curr != NULL) {
        if (curr -> data % 2 == 0) {
            pe -> next = curr;
            pe = curr;
        } else {
            po -> next = curr;
            po = curr;
        }
        curr = curr -> next;
    }
    po -> next = nullptr;
    pe -> next = oh -> next;

    return eh -> next;
}

int main() {
    int n;
    cin >> n;

    int data;
    Node *head = NULL, *temp = NULL;
    for (int i = 1; i <= n; i++) {
        cin >> data;
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp -> next = newNode;
            temp = temp -> next;
        }
    }
    printLL(head);
    cout << endl;
    Node *nHead = segregateEvenOdd(head);
    printLL(nHead);
}