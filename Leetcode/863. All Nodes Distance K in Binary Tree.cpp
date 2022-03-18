
class Solution {
private:
    vector<int> ans;
    
    void kDistNodes(TreeNode *root, int k, TreeNode *block){
        if(root == nullptr or root == block) return;
        
        if(k == 0){
            ans.push_back(root->val);
            return;
        }
        kDistNodes(root->left, k-1, block);
        kDistNodes(root->right, k-1, block);
    }
    
    bool distanceK_(TreeNode *root, TreeNode *target, int &k){
        if(root == nullptr) return false;
        
        if(root == target){
            kDistNodes(root, k, nullptr);
            k--;
            return true;
        }
        
        bool left = distanceK_(root->left, target, k);
        bool right = distanceK_(root->right, target, k);
        
        if(left){
            kDistNodes(root, k, root->left);
            k--;
            return true;
        }
        if(right){
            kDistNodes(root, k, root->right);
            k--;
            return true;
        }
        return false;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        distanceK_(root, target, k);
        
        return ans;
    }
};