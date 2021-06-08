#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[2];
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node *next;

//     Node(int data) {
//         this -> data = data;
//         this -> next = NULL;
//     }
// };

// void printll(Node *head) {
//     Node *th = head;
//     while (th != NULL) {
//         cout << th -> data << " ";
//         th = th -> next;
//     }
//     cout << endl;
// }

// Node *reversell(Node *head) {
//     Node *prev = NULL;
//     Node *curr = head;
//     Node *forw = NULL;
//     while (curr != NULL) {
//         forw = curr -> next;
//         curr -> next = prev;
//         prev = curr;
//         curr = forw;
//     }
//     return prev;
// }

// Node *reverseInRange(Node *head, int s, int e) {
//     if (head == NULL || head -> next == NULL) return head;

//     int init = s;
//     int count = 1;
//     Node *rh = head;
//     while (count < s - 1) {
//         rh = rh -> next;
//         count++;
//     }
//     Node *it = rh;
//     rh = rh -> next;
//     Node *rt = rh;
//     init = e - s, count = 0;
//     while (count < init) {
//         rt = rt -> next;
//         count++;
//     }
//     Node *eh = rt -> next;
//     it -> next = NULL;
//     rt -> next = NULL;
//     rt = rh;
//     rh = reversell(rh);
//     it -> next = rh;
//     rt ->next = eh;
//     return head;
// }

// int main() {
//     int nodes;
//     cin >> nodes;

//     int data;
//     Node *head = NULL;
//     Node *temp = NULL;

//     for (int i = 1; i <= nodes; i++) {
//         cin >> data;
//         Node *newNode = new Node(data);
//         if (head == NULL) {
//             head = newNode;
//             temp = newNode;
//         } else {
//             temp -> next = newNode;
//             temp = temp -> next;
//         }
//     }

//     // printll(head);

//     Node *nHead = reverseInRange(head, 2, 4);

//     printll(nHead);

//     return 0;
// }