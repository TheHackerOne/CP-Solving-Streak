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


int countNodes(Node *head) {
    Node *thead = head;
    int count = 0;
    while (thead != nullptr) {
        thead = thead -> next;
        count++;
    }
    return count;
}

Node *oh = nullptr, *ot = nullptr;
Node *th = nullptr, *tt = nullptr;

void addfirst(Node *node) {
    if (th == nullptr) {
        th = node;
        tt = node;
    } else {
        node -> next = th;
        th = node;
    }
}

Node *reverseInKGroup(Node *head, int k)
{
    if (head == nullptr || head -> next == nullptr || k == 0)
        return head;
    int length = countNodes(head);
    Node *curr = head;
    Node *forw = nullptr;

    while (length >= k) {
        int n = k;
        while (n--) {
            forw = curr -> next;
            curr -> next = nullptr;
            addfirst(curr);
            curr = forw;
        }
        if (oh == nullptr) {
            oh = th;
            ot = tt;
        } else {
            ot -> next = th;
            ot = tt;
        }
        tt = nullptr;
        th = nullptr;
        length -= k;
    }
    ot -> next = curr;
    return oh;
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
    Node *nHead = reverseInKGroup(head, 2);
    printLL(nHead);
}