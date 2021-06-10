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
    if (head == nullptr || head -> next == nullptr) return head;
    Node *dummy = new Node(-500);
    Node *itr = dummy;
    itr -> next = head;
    Node *forw = head -> next;
    while (forw != nullptr) {
        bool flag = false;
        while (forw != nullptr && itr -> next -> data == forw -> data) {
            flag = true;
            forw = forw -> next;
        }
        if (flag == true) {
            itr -> next = forw;
        } else {
            itr = itr -> next;
        }
        if (forw != nullptr) forw = forw -> next;
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