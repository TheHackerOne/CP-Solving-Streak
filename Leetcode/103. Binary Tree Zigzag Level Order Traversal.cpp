class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size, 0);
            for(int i=0;i<size;i++){
                TreeNode *node = q.front();
                q.pop();
                int idx = (leftToRight ? i : size-i-1 );
                temp[idx] = node->val;
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            ans.push_back(temp);
            leftToRight = !leftToRight;
        }
        
        return ans;
    }
};