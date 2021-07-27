#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) {
        this -> data = data;
        left = right = NULL;
    }
};

class pairNode {
public:
    int min;
    int max;
    bool isBST;
};

TreeNode* takeInput() {
    int data;
    cin >> data;
    TreeNode *root = new TreeNode(data);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *front = q.front();
        q.pop();
        int left;
        cin >> left;
        if (left != -1) {
            TreeNode *newNode = new TreeNode(left);
            front -> left = newNode;
            q.push(newNode);
        }
        int right;
        cin >> right;
        if (right != -1) {
            TreeNode *newNode = new TreeNode(right);
            front -> right = newNode;
            q.push(newNode);
        }
    }
    return root;
}

void printTree(TreeNode *root) {
    if (root == NULL) return;

    cout << root -> data << endl;

    printTree(root -> left);
    printTree(root -> right);
}

void PrintTreeClean(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *front = q.front();
        q.pop();
        cout << front -> data << " : ";
        if (front -> left != NULL) {
            cout << front -> left -> data << " ";
            q.push(front -> left);
        }
        if (front -> right != NULL) {
            cout << front -> right -> data << " ";
            q.push(front -> right);
        }
        cout << endl;
    }
}



pairNode isBST(TreeNode *root) {
    if (root == NULL) {
        pairNode ans;
        ans.max = INT_MIN;
        ans.min = INT_MAX;
        ans.isBST = true;
        return ans;
    }

    pairNode left = isBST(root -> left);
    pairNode right = isBST(root -> right);

    pairNode ans;
    ans.isBST = (left.isBST && right.isBST && left.max < root -> data && root -> data < right.min) ? true : false;
    ans.min = min(left.min, min(right.min, root -> data));
    ans.max = max(root -> data, max(left.max, right.max));

    return ans;
}

int main() {
    TreeNode *root = takeInput();

    pairNode ans = isBST(root);

    if (ans.isBST)
        cout << "it is a binary tree";
    else
        cout << "it is not a binary tree";

    return 0;
}

