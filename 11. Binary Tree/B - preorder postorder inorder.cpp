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

void preorder(TreeNode *root) {
    if (root == NULL) return;

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(TreeNode *root) {
    if (root == NULL) return;

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

void inorder(TreeNode *root) {
    if (root == NULL) return;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}


int main() {
    TreeNode *root = takeInput();
    // printTree(root);
    // PrintTreeClean(root);
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    inorder(root);

    return 0;
}