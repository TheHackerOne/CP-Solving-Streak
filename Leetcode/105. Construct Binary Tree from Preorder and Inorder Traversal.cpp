S - Construct Binary Tree from inorder and preorder

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
public:
    
    TreeNode *buildTreeHelper(vector<int> in, int isi, int iei, vector<int> pre, int psi, int pei){
        if(isi > iei) return NULL;
        
        int idx = isi;
        while(in[idx] != pre[psi]) idx++;
        
        int noOfEle = idx - isi;
        
        TreeNode *left = buildTreeHelper(in, isi, idx - 1, pre, psi+1, psi + noOfEle);
        TreeNode *right = buildTreeHelper(in, idx + 1, iei, pre, psi + noOfEle + 1, pei);
        
        TreeNode *newNode = new TreeNode(pre[psi]);
        newNode -> left = left;
        newNode -> right = right;
        
        return newNode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(inorder, 0, inorder.size()-1, preorder,0, preorder.size()-1);
    }
};