class Solution
{
public:
    Node *lcaHelper(Node *root, int n1, int n2) {
        // base case
        if (root == nullptr) return nullptr;

        // main logic
        if (root -> data == n1 || root -> data == n2) {
            return root;
        }

        Node *left = lcaHelper(root -> left, n1, n2);
        Node *right = lcaHelper(root -> right, n1, n2);

        if (left != nullptr && right != nullptr) return root;
        else if (left == nullptr && right == nullptr) return nullptr;
        else return (left == nullptr ? right : left);
    }

    Node* lca(Node* root , int n1 , int n2 )
    {
        struct Node *ans = lcaHelper(root, n1, n2);
        struct Node *def = new Node;
        def -> data = -1;
        if (ans != nullptr) return ans;
        else return def;
    }
};