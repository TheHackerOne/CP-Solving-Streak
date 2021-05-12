#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode {

public:
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;

	BinaryTreeNode(int data) {
		this -> data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {
		delete left;
		delete right;
	}
};

BinaryTreeNode *TakeInput() {
	int data;
	cin >> data;
	BinaryTreeNode *root = new BinaryTreeNode(data);
	queue<BinaryTreeNode *> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty()) {
		BinaryTreeNode *front = pendingNodes.front();
		pendingNodes.pop();
		int left, right;
		cout << "Enter left child of " << front -> data << endl;
		cin >> left;
		if (left != -1) {
			BinaryTreeNode *newNode = new BinaryTreeNode(left);
			front -> left = newNode;
			pendingNodes.push(newNode);
		}
		cout << "Enter right child of " << front -> data << endl;
		cin >> right;
		if (right != -1) {
			BinaryTreeNode *newNode = new BinaryTreeNode(right);
			front -> right = newNode;
			pendingNodes.push(newNode);
		}
	}
	return root;
}

void PrintBinaryTree(BinaryTreeNode *root) {
	if (root == NULL)
		return;
	cout << root -> data;
	PrintBinaryTree(root -> left);
	PrintBinaryTree(root -> right);
}

int main() {
	BinaryTreeNode *root = TakeInput();
	PrintBinaryTree(root);

	return 0;
}