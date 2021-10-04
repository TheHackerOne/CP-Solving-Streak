class Solution
{
public:
    Node *lca(Node *root, int a, int b) {
        // base case
        if (root == nullptr || root -> data == a || root -> data == b) return root;

        // main logic
        Node *left = lca(root -> left, a, b);
        Node *right = lca(root -> right, a, b);
        if (left == nullptr) {
            return right;
        } else if (right == nullptr) {
            return left;
        } else {
            return root;
        }
    }

    int dist(Node *root, int node, int level) {
        // base case
        if (root == nullptr) return -1;

        // main logic
        if (root -> data == node) return level;
        int left = dist(root -> left, node, level + 1);
        if (left != -1) return left ;
        int right = dist(root -> right, node, level + 1);
        if (right != -1) return right;
        else return -1;
    }

    int findDist(Node *root, int a, int b) {
        Node *lcaNode = lca(root, a, b);
        // cout<<lcaNode -> data<<endl;
        int distOne = dist(lcaNode, a, 0);
        int distTwo = dist(lcaNode, b, 0);
        return distOne + distTwo;
    }
};