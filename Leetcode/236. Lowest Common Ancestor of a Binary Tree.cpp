class Solution {
public:
    bool nodeToRoot(TreeNode *root, vector<TreeNode*> &path, TreeNode *node){
        // base case
         if(root == nullptr) return false;

        // main logic
         if(root == node){
            path.push_back(root);
            return true;
         }

         bool left = nodeToRoot(root->left, path, node);
         bool right = nodeToRoot(root->right, path, node);
         if(left or right){
            path.push_back(root);
            return true;
         }else return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(p == q) return p;
         vector<TreeNode*> path1, path2;
         nodeToRoot(root, path1, p);
         nodeToRoot(root, path2, q);
         int p1 = path1.size()-1, p2 = path2.size()-1;
         while(p1 >= 0 and p2 >= 0 and path1[p1] == path2[p2]){
         p1--,p2--;
         }
         return path1[p1+1];
    }
};