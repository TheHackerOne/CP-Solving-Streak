class Solution {
public:
	unordered_map<string, int> mp;

	string solve(Node *root) {
		// base case
		if (root == nullptr) {
			return "N";
		}
		string s = "";
		if (root -> left == nullptr && root -> right == nullptr) {
			s += to_string(root -> data);
			return s;
		}
		// main logic
		s += to_string(root -> data);
		s += solve(root -> left);
		s += solve(root -> right);
		mp[s]++;
		return s;
	}

	bool dupSub(Node *root) {
		solve(root);
		for (auto i : mp) {
			int count = i.second;
			if (count >= 2) return 1;
		}
		return 0;
	}
};