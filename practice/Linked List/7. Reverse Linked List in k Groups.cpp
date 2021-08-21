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

Node *th = NULL, *tt = NULL;

void addFirst(Node *node) {
	if (th == NULL) {
		th = node;
		tt = node;
	} else {
		node -> next = th;
		th = node;
	}
}

int lenLL(Node *head) {
	int count = 0;
	while (head != NULL) {
		head = head -> next;
		count++;
	}
	return count;
}

Node *reverseInKgroups(Node *head, int k) {
	Node *h1 = head, *oh = NULL, *ot = NULL;
	int length = lenLL(head);
	while (h1 != NULL && length >= k) {
		int steps = k;
		while (steps--) {
			Node *curr = h1;
			h1 = h1 -> next;
			curr -> next = NULL;
			addFirst(curr);
		}
		if (oh == NULL) {
			oh = th;
			ot = tt;
		} else {
			ot -> next = th;
			ot = tt;
		}
		tt = th = NULL;
		length -= k;
	}
	ot -> next = h1;
	return oh;
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

	Node *h1 = reverseInKgroups(head, 3);
	printList(h1);

	return 0;
}