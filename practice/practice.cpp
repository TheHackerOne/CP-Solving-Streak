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

int midElement(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast -> next != NULL && fast -> next -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow -> data;
}

void printLL(Node *head) {
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int data;
    Node *head = NULL;
    Node *temp = NULL;
    for (int i = 0; i < n; i++) {
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
    cout << "Mid element = " << midElement(head) << endl;

    return 0;
}