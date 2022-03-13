/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool path(TreeNode *root, TreeNode *target, vector<TreeNode*> &p){
        // base case
        if(root == nullptr) return false;
        
        // main logic
        if(root == target){
            p.push_back(root);
            return true;
        }
        
        bool leftTree = path(root->left, target, p);
        bool rightTree = path(root->right, target, p);
        if(leftTree or rightTree){
            p.push_back(root);
            return true;
        }
        return false;
    }
    
    void nodesKDistanceAway(TreeNode *root, int k, TreeNode *block, vector<int> &ans){
        // base case
        if(root == nullptr or root == block) return;
        
        // main logic
        if(k == 0) {
            ans.push_back(root->val);
            return;
        }
        nodesKDistanceAway(root->left, k-1, block, ans);
        nodesKDistanceAway(root->right, k-1, block, ans);
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> nodeToRootPath;
        path(root, target, nodeToRootPath);
        // reverse(nodeToRootPath.begin(), nodeToRootPath.end());
        vector<int> ans;
        for(int i = 0;i < nodeToRootPath.size();i++){
            nodesKDistanceAway(nodeToRootPath[i], k-i, i-1>=0?nodeToRootPath[i-1]:nullptr,ans);
        }
        return ans;
    }
};