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
    TreeNode *buildTreeHelper(vector<int> preorder, vector<int> inorder, int is, int ie, int ps, int pe) {
        // base case
        if (is > ie) {
            return nullptr;
        }
        // main logic
        TreeNode *newNode = new TreeNode(preorder[ps]);
        int idx = is, rootEle = preorder[ps];
        while (inorder[idx] != rootEle) {
            idx++;
        }
        int noofEle = idx - is;
        int lis = is;
        int lie = idx - 1;
        int lps = ps + 1;
        int lpe = ps + noofEle;
        int ris = idx + 1;
        int rie = ie;
        int rps = ps + noofEle + 1;
        int rpe = pe;
        newNode -> left = buildTreeHelper(preorder, inorder, lis, lie, lps, lpe);
        newNode -> right = buildTreeHelper(preorder, inorder, ris, rie, rps, rpe);
        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
    }
};