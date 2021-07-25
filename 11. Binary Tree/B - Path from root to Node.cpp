#include<bits/stdc++.h>
using namespace std;

// Path from root to Node

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

vector<int> path;

bool NodetoRootPath(TreeNode *root, int ele) {
    if (root == NULL) return false;

    if (root -> data == ele) {
        path.push_back(root -> data);
        return true;
    }

    if (NodetoRootPath(root -> left, ele)) {
        path.push_back(root -> data);
        return true;
    }

    if (NodetoRootPath(root -> right, ele)) {
        path.push_back(root -> data);
        return true;
    }

    return false;
}

int main() {
    TreeNode *root = takeInput();
    // printTree(root);
    // PrintTreeClean(root);
    NodetoRootPath(root, 5);
    for (int i : path)
        cout << i << " ";

    return 0;
}