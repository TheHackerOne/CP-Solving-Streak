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
		cout << "destructor called " << data << endl;
		delete next;
	}
};

Node *TakeInput() {
	int data;
	Node *head = NULL;
	Node *temp = NULL;
	cin >> data;
	while (data != -1) {
		Node *newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			temp = newNode;
		} else {
			temp -> next = newNode;
			temp = temp -> next;
		}
		cin >> data;
	}
	return head;
}

void PrintLinkedList(Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
}

int main() {
	Node *head = TakeInput();
	PrintLinkedList(head);
	cout << endl;
	delete head;

	return 0;
}