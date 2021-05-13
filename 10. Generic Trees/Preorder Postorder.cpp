#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int data;
	vector<TreeNode *> children;

	TreeNode(int data) {
		this -> data = data;
	}

	~TreeNode() {
		for (int i = 0; i < children.size(); i++) {
			delete children[i];
		}
	}
};

void printTree(TreeNode *root) {
	cout << root -> data << " ";
	for (int i = 0; i < root -> children.size(); i++) {
		printTree(root -> children[i]);
	}
}

TreeNode *TakeInput() {
	int data;
	cout << "enter root node" << endl;
	cin >> data;
	TreeNode *root = new TreeNode(data);
	queue<TreeNode *> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty()) {
		TreeNode *front = pendingNodes.front();
		pendingNodes.pop();
		int n;
		cout << "Enter the num of children of " << front -> data << endl;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int child;
			cout << "Enter children " << i + 1 << endl;
			cin >> child;
			TreeNode *newNode = new TreeNode(child);
			pendingNodes.push(newNode);
			front -> children.push_back(newNode);
		}
	}
	return root;
}

int NumberOfNodes(TreeNode *root) {
	int ans = 1;
	for (int i = 0; i < root -> children.size(); i++)
		ans += NumberOfNodes(root -> children[i]);
	return ans;
}

int HeightOfTree(TreeNode *root) {
	int maxH = 0;
	for (int i = 0; i < root -> children.size(); i++)
		maxH = max(maxH, HeightOfTree(root -> children[i]));
	return 1 + maxH;
}

void PreOrder(TreeNode *root) {
	cout << root -> data << " ";
	for (int i = 0; i < root -> children.size(); i++) {
		PreOrder(root -> children[i]);
	}
}

void PostOrder(TreeNode *root) {
	for (int i = 0; i < root -> children.size(); i++) {
		PostOrder(root -> children[i]);
	}
	cout << root -> data << " ";
}

void PrintTreeClean(TreeNode *root) {
	queue<TreeNode *> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty()) {
		TreeNode *front = pendingNodes.front();
		pendingNodes.pop();
		cout << front -> data << " : ";
		for (int i = 0; i < front -> children.size(); i++) {
			cout << front -> children[i] -> data;
			pendingNodes.push(front -> children[i]);
		}
		cout << endl;
	}
}

int main() {

	TreeNode *root = TakeInput();
	PrintTreeClean(root);
	cout << endl << "Number of nodes = " << NumberOfNodes(root) << endl;
	// cout << endl << "Height of Generic Tree = " << HeightOfTree(root) << endl;
	cout << "PreOrder : ";
	PreOrder(root);
	cout << endl;
	cout << "PostOrder : ";
	PostOrder(root);
	delete root;

	return 0;
}
// 1 3 2 3 4 2 5 6 1 7 1 8 0 0 0 1 9 0