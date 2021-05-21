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

Node *reverseLL(Node *head) {
    Node *d = NULL;
    Node *next = NULL;
    while (head != NULL) {
        next = head -> next;
        head -> next = d;
        d = head;
        head = next;
    }
    return d;
}


Node *midElement(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast -> next != NULL && fast -> next -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}


bool isPalindrome(Node *head) {
    Node *mid = midElement(head);
    mid -> next = reverseLL(mid -> next);
    Node *secondHalf = mid -> next;
    while (secondHalf != NULL) {
        if (head->data == secondHalf->data) {
            head = head -> next;
            secondHalf = secondHalf -> next;
        } else {
            return false;
        }
    }
    return true;
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

    if (isPalindrome(head))
        cout << "Given Linked List is a Palindrome " << endl;
    else
        cout << "Given Linked List is not a Palindrome" << endl;

    return 0;
}