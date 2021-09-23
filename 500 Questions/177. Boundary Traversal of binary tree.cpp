class Solution {
public:

    void inorder(Node *root, vector<int> &a) {
        if (root == nullptr) return;
        inorder(root -> left, a);
        if (root -> left == nullptr && root -> right == nullptr)
            a.push_back(root -> data);
        inorder(root -> right, a);
    }

    vector <int> printBoundary(Node *root)
    {
        vector<int> ans;
        if (root == nullptr) return ans;
        ans.push_back(root -> data);
        Node *curr = root -> left;
        // left side of tree
        while (curr != nullptr && (curr -> left != nullptr || curr -> right != nullptr)) {
            ans.push_back(curr -> data);
            if (curr -> left != nullptr) curr = curr -> left;
            else curr = curr -> right;
        }

        // inorder traversal for leafs
        inorder(root, ans);

        // right side of tree
        stack<int> s;
        curr = root -> right;
        while (curr != nullptr && (curr -> left != nullptr || curr -> right != nullptr)) {
            s.push(curr -> data);
            if (curr -> right != nullptr) curr = curr -> right;
            else curr = curr -> left;
        }
        while ( !s.empty()) {
            int ele = s.top();
            s.pop();
            ans.push_back(ele);
        }
        return ans;
    }
};