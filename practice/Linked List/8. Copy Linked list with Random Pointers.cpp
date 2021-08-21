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

Node *copyRandomList(Node *head)
{
	Node *curr = head, *forw = NULL;
	while (curr != NULL) {
		forw = curr -> next;
		Node *newNode = new Node(curr -> val);
		curr -> next = newNode;
		newNode -> next = forw;
		curr = forw;
	}

	curr = head, forw = NULL;
	while (curr != NULL) {
		forw = curr -> next;
		if (curr -> random == NULL) forw -> random = NULL;
		else forw -> random = curr -> random -> next;
		curr = forw -> next;
	}

	curr = head -> next;
	while (curr != NULL && curr -> next != NULL) {
		curr -> next = curr -> next -> next;
		curr = curr -> next;
	}

	return head -> next;
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


	return 0;
}


