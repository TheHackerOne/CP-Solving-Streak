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

Node *removeNthNodeFromEnd(Node *head, int n) {
    if (head == NULL)
        return head;
    int length = countNode(head);
    if (n > length)
        return head;
    if (n == length) {
        Node *th = head;
        head = th -> next;
        th -> next = NULL;
        delete(th);
        return head;
    }
    Node *th = head;
    int sn = length - n;
    int count = 1;
    while (count < sn) {
        th = th -> next;
        count++;
    }
    Node *dNode = th -> next;
    th -> next = dNode -> next;
    dNode -> next = NULL;
    delete(dNode);
    return head;
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
    Node *nHead = removeNthNodeFromEnd(head, 5);
    printLL(nHead);
}