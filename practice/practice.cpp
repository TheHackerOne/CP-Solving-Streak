class Solution {
private:
    bool solve(TreeNode *root1, TreeNode *root2){
        // base case
        if(!root1 and !root2) return true;
        if((root1 and !root2) or (!root1 and root2)) return false;
        
        // main logic
        if(root1->val == roo2->val){
            return solve(root1->left, root2->right) and solve(root1->right, root2->left);
        }
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root, root);
    }
};