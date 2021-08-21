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

Node *fold(Node *head) {
	Node *mid = midEle(head);
	Node *h1 = head;
	Node *h2 = mid -> next;
	mid -> next = NULL;
	h2 = reversell(h2);
	Node *c1 = h1, *c2 = h2, *forw1 = NULL, *forw2 = NULL;
	while (c2 != NULL) {
		forw1 = c1 -> next;
		forw2 = c2 -> next;
		c1 -> next = c2;
		c2 -> next = forw1;
		c1 = forw1;
		c2 = forw2;
	}
	return h1;
}

Node *unfold(Node *head) {
	Node *h1 = head, *h2 = head -> next;
	Node *c1 = h1, *c2 = h2;
	while (c1 != NULL && c2 != NULL) {
		c1 -> next = c1 -> next -> next;
		c2 -> next = c2 -> next -> next;
		c1 = c1 -> next;
		c2 = c2 -> next;
	}

	h2 = reversell(h2);
	c1 -> next = h2;

	return h1;
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

	Node *h1 = fold(head);
	printList(h1);

	Node *h = unfold(h1);
	printList(h);

	return 0;
}