class Solution
{
public:

	int a[2] = {0, 0};

	void widthTree(Node *root, int hl) {
		if (root == NULL) return;
		a[1] = max(a[1], hl);
		a[0] = min(a[0], hl);
		widthTree(root -> left, hl - 1);
		widthTree(root -> right, hl + 1);
	}

	vector<int> topView(Node *root) {
		widthTree(root, 0);
		int width = a[1] - a[0] + 1;
		int rootVertLevel = abs(a[0]);
		vector<int> levels(width, -1);
		queue<pair<Node *, int>> q;
		q.push({ root, rootVertLevel });
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				pair<Node *, int> curr = q.front();
				q.pop();
				if (levels[curr.second] == -1) levels[curr.second] = curr.first -> data;
				if (curr.first -> left != NULL) {
					q.push({ curr.first -> left, curr.second - 1 });
				}
				if (curr.first -> right != NULL) {
					q.push({ curr.first -> right, curr.second + 1 });
				}
			}
		}
		return levels;
	}

};