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

void printKLevelsDownBFS(TreeNode *root, int k) {
    queue < pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        int size = q.size();
        pair<TreeNode *, int> curr = q.front();
        int level = curr.second;

        if (level == k) {
            while (!q.empty()) {
                cout << q.front().first -> data << " ";
                q.pop();
            }
            break;
        }

        while (size-- && level != k) {
            pair<TreeNode *, int> curr = q.front();
            q.pop();
            if (curr.first -> left != NULL)
                q.push({curr.first -> left, level + 1});
            if (curr.first -> right != NULL)
                q.push({curr.first -> right, level + 1});
        }
    }
}

void printKLevelsDownDFS(TreeNode *root, int level) {
    if (root == NULL) return;

    if (level == 0) {
        cout << root -> data << " ";
        return;
    }
    printKLevelsDownDFS(root -> left, level - 1);
    printKLevelsDownDFS(root -> right, level - 1);
}

int main() {
    TreeNode *root = takeInput();
    // printTree(root);
    // PrintTreeClean(root);
    printKLevelsDownBFS(root, 2);
    cout << endl;
    printKLevelsDownDFS(root, 2);

    return 0;
}