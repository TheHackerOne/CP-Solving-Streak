vector <int> zigZagTraversal(Node* root)
{
	deque<Node *> q;
	vector<int> ans;
	q.push_back(root);
	int flag = 0;
	while (!q.empty()) {
		int size = q.size();

		if (flag) {
			while (size--) {
				Node *curr = q.back();
				q.pop_back();
				ans.push_back(curr -> data);
				if (curr -> right != NULL) q.push_front(curr -> right);
				if (curr -> left != NULL) q.push_front(curr -> left);
				flag = 0;
			}
		} else {
			while (size--) { // reverse(q.begin(), q.end());
				Node *curr = q.front();
				q.pop_front();
				ans.push_back(curr -> data);
				if (curr -> left != NULL) q.push_back(curr -> left);
				if (curr -> right != NULL) q.push_back(curr -> right);
				flag = 1;
			}
		}
	}

	return ans;
}