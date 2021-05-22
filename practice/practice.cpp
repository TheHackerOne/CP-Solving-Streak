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
        cout << "hello" << endl;
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

    printLL(head);
    Node *mid = midElement(head);
    cout << endl << "Mid element = " << mid->data << endl;
    Node *nHead = reverseLL(head);
    printLL(nHead);

    return 0;
}