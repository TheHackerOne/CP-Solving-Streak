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

Node *midEle(Node *head) {
	Node *f = head;
	Node *s = head;
	while (f -> next != NULL && f -> next -> next != NULL) {
		s = s -> next;
		f = f -> next -> next;
	}
	return s;
}

Node *reversell(Node *head) {
	Node *prev = NULL;
	Node *curr = head;
	Node *forw = NULL;
	while (curr != NULL) {
		forw = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = forw;
	}
	return prev;
}

void printList(Node *head) {
	while (head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}

Node *mergeTwoLL(Node *head1, Node *head2) {
	Node *dummy = new Node(-1);
	Node *prev = dummy;
	Node *c1 = head1, *c2 = head2;
	while (c1 != NULL && c2 != NULL) {
		if (c1 -> data < c2 -> data) {
			prev -> next = c1;
			prev = c1;
			c1 = c1 -> next;
		} else {
			prev -> next = c2;
			prev = c2;
			c2 = c2 -> next;
		}
	}
	prev -> next = (c1 == NULL) ? c2 : c1;
	return dummy -> next;
}

Node *mergeSort(Node *head) {
	if (head == NULL || head -> next == NULL) {
		return head;
	}
	Node *mid = midEle(head);
	Node *h1 = head;
	Node *h2 = mid -> next;
	mid -> next = NULL;
	Node *newh1 = mergeSort(h1);
	Node *newh2 = mergeSort(h2);
	return mergeTwoLL(newh1, newh2);
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


	Node *h = mergeSort(head);
	printList(h);


	return 0;
}