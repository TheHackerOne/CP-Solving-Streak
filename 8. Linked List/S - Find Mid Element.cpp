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

Node* findMid(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast -> next != NULL && fast -> next -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    cout << "Mid element -> " << slow->data << endl;
    return slow;
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
            temp = newNode;
        } else {
            temp -> next = newNode;
            temp = temp -> next;
        }
    }
    printLL(head);
    cout << endl;
    Node *middle = findMid(head);
    printLL(middle);

    return 0;
}