class Solution
{
public:
    class Pair {
    public:
        int sum = 0;
        bool sumTree = true;
    };

    Pair isSumTreeHelper(Node *root) {
        // base case
        if (root == nullptr) {
            Pair p;
            return p;
        }
        if (root -> left == nullptr && root -> right == nullptr) {
            Pair p;
            p.sum = root -> data;
            return p;
        }

        // main logic
        Pair left = isSumTreeHelper(root -> left);
        Pair right = isSumTreeHelper(root -> right);
        Pair ans;
        ans.sum = left.sum + right.sum + root -> data;
        if ((left.sum + right.sum == root -> data) && (left.sumTree) && (right.sumTree)) {
            ans.sumTree = true;
            return ans;
        } else {
            ans.sumTree = false;
            return ans;
        }
    }
    bool isSumTree(Node* root)
    {
        if (root == nullptr || (root -> left == nullptr && root->right == nullptr)) return true;
        return isSumTreeHelper(root).sumTree;
    }
};