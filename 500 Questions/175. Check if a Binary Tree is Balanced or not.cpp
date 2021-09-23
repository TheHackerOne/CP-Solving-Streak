class Solution {
public:
	//Function to check whether a binary tree is balanced or not.
	class Pair {
	public:
		int maxleftHeight = 0;
		int maxrightHeight = 0;
		bool isBalanced = true;
	};

	Pair isBalancedHelper(Node *node) {
		if (node == NULL) {
			Pair p;
			return p;
		}
		Pair left = isBalancedHelper(node -> left);
		Pair right = isBalancedHelper(node -> right);
		Pair p;
		p.maxleftHeight = 1 + max(left.maxleftHeight, left.maxrightHeight);
		p.maxrightHeight = 1 + max(right.maxrightHeight, right.maxleftHeight);
		if (abs(p.maxleftHeight - p.maxrightHeight) <= 1 && left.isBalanced && right.isBalanced) {
			p.isBalanced = true;
		} else {
			p.isBalanced = false;
		}
		return p;
	}

	bool isBalanced(Node *root)
	{
		//  Your Code here
		return isBalancedHelper(root).isBalanced ? 1 : 0;
	}
};