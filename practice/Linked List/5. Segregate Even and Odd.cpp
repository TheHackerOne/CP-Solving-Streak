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

pair<Node *, Node *> segEvenAndOdd(Node *head) {
	Node *deven = new Node(-1);
	Node *dodd = new Node(-1);
	Node *prevOdd = dodd, *prevEven = deven;
	Node *curr = head;
	while (curr != NULL) {
		if (curr -> data % 2 == 0) {
			prevEven -> next = curr;
			prevEven = curr;
		} else {
			prevOdd -> next = curr;
			prevOdd = curr;
		}
		curr = curr -> next;
	}
	prevEven -> next = NULL, prevOdd -> next = NULL;
	pair<Node *, Node *> ans;
	ans.first = deven -> next;
	ans.second = dodd -> next;
	return ans;
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


	pair<Node*, Node*> ans = segEvenAndOdd(head);
	printList(ans.first);
	printList(ans.second);


	return 0;
}