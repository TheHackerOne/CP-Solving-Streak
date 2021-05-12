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

int CountNodesBasic(Node *head) {
	Node *temp = head;
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp -> next;
	}
	return count;
}

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
	cout << "Numer of Nodes = " << CountNodesBasic(head) << endl;
	delete head;

	return 0;
}