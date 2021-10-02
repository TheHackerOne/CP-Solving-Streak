class Solution {
public:
	/*You are required to complete this method*/
	int leafLevel = 0;

	bool checkHelper(Node *root, int level) {
		if (root == nullptr) {
			return true;
		}
		if (root -> left == nullptr && root -> right == nullptr) {
			if (leafLevel == 0) {
				leafLevel = level;
				return true;
			}
			else if (leafLevel == level) {
				return true;
			}
			return false;
		}
		bool left = checkHelper(root -> left, level + 1);
		bool right = checkHelper(root -> right, level + 1);
		if (left && right) return true;
		else return false;
	}

	bool check(Node *root) {
		return checkHelper(root, 0);
	}
};