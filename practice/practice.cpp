class Solution
{
private:
	int minw = INT_MAX, maxw = INT_MIN;
	void width(Node *root, int w){
		if(root == nullptr) return;

		minw = min(minw, w);
		maxw = max(maxw, w);
		width(root->left, w-1); 
		width(root->right, w+1); 
	}

	void verticalOrder(Node *root, int level, unordered_map<int, vector<int>> &mp){
		// base case
		if(roto == nullptr) return;

		// main logic
		mp[level] = root->val;
		verticalOrder(root->left, level-1, mp)
		verticalOrder(root->right, level+1, mp)
	}

public:
	vector<int> verticalOrder(Node *root)
	{
	 	width(root);
	 	int widthOfTree = maxw-minw+1;
	 	unordered_map<int, vector<int>> mp;
	 	int rootLevel = abs(minw);
	 	verticalOrder(root, rootLevel, mp);
	 	vector<int> ans;
	 	for(int i=0;i<=maxw+abs(minw);i++){
	 		for(auto j:mp[i]){
	 			ans.push_back(j);
	 		}
	 	}
	 	return ans;
	}
};