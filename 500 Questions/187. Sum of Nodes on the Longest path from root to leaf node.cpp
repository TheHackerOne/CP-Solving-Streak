

class Solution
{
public:
	int max_sum = INT_MIN, max_level = INT_MIN;

	void helper(Node *root, int level, int sum) {
		//base case
		if (root == nullptr) {
			return;
		}
		if (root -> left == nullptr && root -> right == nullptr) {
			if (level > max_level) {
				max_sum = sum + root->data;
				max_level = level;
			} else if (level == max_level) {
				max_sum = max(max_sum, sum + root->data);
			}
			return;
		}
		// main logic
		helper(root -> left, level + 1, sum + root -> data);
		helper(root -> right, level + 1, sum + root -> data);
	}
	int sumOfLongRootToLeafPath(Node *root)
	{
		helper(root, 0, 0);
		return max_sum;
	}
};