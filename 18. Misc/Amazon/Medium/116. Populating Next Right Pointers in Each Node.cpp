

class Solution {
private:
    void recur(Node *root, Node *parent){
        // base case
        if(root == nullptr) return;
        
        // main logic
        if(parent == nullptr) {
            root->next = nullptr;
            recur(root->left, root);
            recur(root->right, root);
        }else{
            if(parent->left == root){
                root->next = parent->right;
            }else if(parent->right == root){
                root->next = parent->next != nullptr ? parent->next->left : nullptr;
            }
            recur(root->left, root);
            recur(root->right, root);
        }
    }
public:
    Node* connect(Node* root) {
        recur(root, nullptr);
        return root;
    }
};