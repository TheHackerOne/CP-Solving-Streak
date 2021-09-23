#include<bits/stdc++.h>
using namespace std;

vector<int> diagonalTraversal(Node *node) {
	vector<int> ans;
	queue<Node *> q;
	q.push(node);
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			Node *curr = q.front();
			q.pop();
			while (curr != NULL) {
				ans.push_back(curr -> data);
				if (curr -> left != NULL) {
					q.push(curr -> left);
				}
				curr = curr -> right;
			}
		}
	}
	return ans;
}

int main() {


	return 0;
}