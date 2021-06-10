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

Node *oh = nullptr;
Node *ot = nullptr;

void printll(Node *head) {
    Node *t =  head;
    while (t != NULL) {
        cout << t -> data << " ";
        t = t -> next;
    }
    cout << endl;
}

void addLast(Node *node) {
    ot -> next = node;
    ot = ot -> next;
}

Node* deleteDuplicates(Node* head) {
    Node *dummy = new Node(INT_MIN);
    oh = dummy;
    ot = dummy;
    Node *curr = head;
    Node *forw = nullptr;
    while (curr != nullptr) {
        forw = curr -> next;
        if (curr -> data != ot -> data) {
            curr -> next = nullptr;
            addLast(curr);
        }
        curr = forw;
    }
    return dummy -> next;
}

int main() {
    int n;
    cin >> n ;

    Node *head = NULL;
    Node *temp = NULL;
    for (int i = 1; i <= n; i++) {
        int data;
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
    printll(head);
    Node *nHead = deleteDuplicates(head);
    printll(nHead);

    return 0;
}