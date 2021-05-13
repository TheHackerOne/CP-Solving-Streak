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

int main() {

	TreeNode *root = TakeInput();
	printTree(root);
	cout << endl << "Number of nodes = " << NumberOfNodes(root) << endl;
	delete root;

	return 0;
}