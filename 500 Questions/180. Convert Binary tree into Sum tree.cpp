class Solution {
public:


	int toSumTreeHelper(Node *root) {
		if (root == NULL) {
			return 0;
		}
		if (root -> left == NULL && root -> right == NULL) {
			int leafSum = root -> data;
			root -> data = 0;
			return leafSum;
		}

		int leftSum = toSumTreeHelper(root -> left);
		int rightSum = toSumTreeHelper(root -> right);
		int nodeSum = leftSum + rightSum + root -> data;
		root -> data = leftSum + rightSum;
		return nodeSum;
	}

	void toSumTree(Node *root) {
		int rootSum = toSumTreeHelper(root);
	}
};