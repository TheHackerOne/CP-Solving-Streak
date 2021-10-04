#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this -> data = data;
        left = nullptr;
        right = nullptr;
    }
};

bool found = false;

int lca(Node *root, int &n1, int k) {
    // base case
    if (root == nullptr) return -1;

    // main logic
    if (root -> data == n1) {
        return 1;
    }
    int left = lca(root -> left, n1, k);
    int right = lca(root -> right, n1, k);
    if (found) return (left != -1 ? left : right);

    if (left == -1 && right == -1) return -1;
    else if (left != -1 ) {
        if (left == k) {
            found = true;
            return root -> data;
        }
        else return left + 1;
    } else {
        if (right == k) {
            found = true;
            return root -> data;
        }
        else return right + 1;
    }
}

int kthAncestor(Node *root, int node, int k) {
    int nodeVal = lca(root, node, k);
    return nodeVal;
}

int main() {
    Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    int ans = kthAncestor(root, 4, 3);
    if (found) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}