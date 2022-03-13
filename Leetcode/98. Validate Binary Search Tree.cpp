/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    class Res{
        public:
        long long int minEle = LONG_MAX;
        long long int maxEle = LONG_MIN;
        bool isBST = true;
    };
    
    long long min(long long a, long long b){
        return a > b ? b : a;
    }
    
    long long max(long long a, long long b){
        return a > b ? a : b;
    }
    
    Res helper(TreeNode *root){
        // base case
        if(root == nullptr){
            Res res;
            return res;
        }
        
        // main logic
        Res leftTree = helper(root->left);
        Res rightTree = helper(root->right);
        
        Res res;
        res.minEle = min( root->val, min(leftTree.minEle, rightTree.minEle) );
        res.maxEle = max( root->val, max(leftTree.maxEle, rightTree.maxEle) );
        if(leftTree.isBST and rightTree.isBST and root->val > leftTree.maxEle and root->val < rightTree.minEle){           
            return res;
        }
        res.isBST = false;
        return res;
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root).isBST;
    }
};