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

	Node *head1 = NULL;
	Node *temp1 = NULL;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		Node *newNode = new Node(data);
		if (head1 == NULL) {
			head1 = newNode;
			temp1 = head1;
		} else {
			temp1 -> next = newNode;
			temp1 = temp1 -> next;
		}
	}

	Node *h = mergeTwoLL(head, head1);
	printList(h);


	return 0;
}