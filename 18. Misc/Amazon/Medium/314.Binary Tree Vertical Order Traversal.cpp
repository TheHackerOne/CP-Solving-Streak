class Solution
{
private:
	int minw = INT_MAX, maxw = INT_MIN;
	unordered_map<int, vector<int>> mp;
	void width(Node *root, int w){
		if(root == nullptr) return;

		minw = min(minw, w);
		maxw = max(maxw, w);
		width(root->left, w-1); 
		width(root->right, w+1); 
	}

	void verticalOrderHelper(Node *root, int hl) {
        queue<pair<Node *, int>> q;
        q.push({ root, hl });
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<Node *, int> curr = q.front();
                q.pop();
                int hl = curr.second;
                mp[hl].push_back(curr.first -> data);
                if (curr.first -> left != NULL) {
                    q.push({ curr.first -> left, hl - 1 });
                }
                if (curr.first -> right != NULL) {
                    q.push({ curr.first -> right, hl + 1 });
                }
            }
        }
    }

public:
	vector<int> verticalOrder(Node *root)
	{
	 	width(root, 0);
	 	int widthOfTree = maxw-minw+1;
	 	mp.clear();
	 	int rootLevel = abs(minw);
	 	verticalOrderHelper(root, rootLevel);
	 	vector<int> ans;
	 	for(int i=0;i<=maxw+abs(minw);i++){
	 		for(auto j:mp[i]){
	 			ans.push_back(j);
	 		}
	 	}
	 	return ans;
	}
};