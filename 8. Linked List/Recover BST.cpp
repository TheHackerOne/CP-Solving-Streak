TreeNode *getRightMostNode(TreeNode *left, TreeNode *curr){
    while(left->right != nullptr and left->right != curr){
        left = left->right;
    }
    return left;
}

void recoverTree(TreeNode *root){
    // morris traversal
    TreeNode *a1 = nullptr, *b1 = nullptr, *a2 = nullptr, *b2 = nullptr;
    TreeNode *prev = nullptr;
    bool prevExist = false;
    TreeNode*curr = root;
    vector<int> inorder;
    while(curr != nullptr){
        TreeNode *left = curr->left;
        if(left == nullptr){
            if(!prevExist){
                prev = curr;
                prevExist =true;
            }else{
                if(prev->val > curr ->val and a1 == nullptr){
                    a1 = prev;
                    b1 = curr;
                }else if(prev->val > curr->val and a2 == nullptr){
                    a2 = prev;
                    b2 = curr;
                }
                prev = curr;
            }      
            inorder.push_back(curr->val);      
            curr = curr->right;
        }else{
            TreeNode *rightMostNode = getRightMostNode(left, curr);
            if(rightMostNode->right == nullptr){
                rightMostNode->right = curr;
                curr = curr->left;
            }else{
                rightMostNode->right = nullptr;
                if(!prevExist){
                    prev = curr;
                    prevExist =true;
                }else{
                    if(prev->val > curr ->val and a1 == nullptr){
                        a1 = prev;
                        b1 = curr;
                    }else if(prev->val > curr->val and a2 == nullptr){
                        a2 = prev;
                        b2 = curr;
                    }
                    prev = curr;
                }  
                inorder.push_back(curr->val);  
                curr = curr->right;
            }
        }
    }
    if(a2 == nullptr){
        swap(a1->val, b1->val);
    }else{
        swap(a1->val, b2->val);
    }
}