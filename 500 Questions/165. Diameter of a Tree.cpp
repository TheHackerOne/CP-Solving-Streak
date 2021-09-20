class Solution {
public:
    // Function to return the diameter of a Binary Tree.
    class tuple {
    public:
        int leftHeight = 0;
        int rightHeight = 0;
        int maxDia = 0;
    };

    tuple diameterTree(Node *root) {
        if (root == nullptr) {
            tuple l;
            return l;
        }
        tuple l = diameterTree(root -> left);
        tuple r = diameterTree(root -> right);
        tuple ans;
        int dia = max(l.leftHeight, l.rightHeight) + max(r.leftHeight, r.rightHeight) + 1;
        ans.maxDia = max({dia, l.maxDia, r.maxDia});
        ans.leftHeight = max(l.leftHeight, l.rightHeight) + 1;
        ans.rightHeight = max(r.leftHeight, r.rightHeight) + 1;
        return ans;
    }

    int diameter(Node* root) {
        tuple t = diameterTree(root);
        return t.maxDia;
    }
};