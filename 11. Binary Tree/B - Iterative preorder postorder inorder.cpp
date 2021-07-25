#include<bits/stdc++.h>
using namespace std;

// Iterative preorder postorder inorder

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

void PrePostInorder(TreeNode *root) {
    stack<pair<TreeNode*, int>> s;
    s.push({root, 1});
    string preorder = "";
    string postorder = "";
    string inorder = "";
    while (!s.empty()) {
        pair<TreeNode*, int> &si = s.top();
        int currlevel = si.second;
        TreeNode *currNode = si.first;
        if (currlevel == 1) {
            preorder = preorder + to_string(currNode -> data) + " ";
            si.second += 1;
            if (currNode -> left != NULL)
                s.push({ currNode -> left, 1 });
        } else if (currlevel == 2) {
            inorder = inorder + to_string(currNode -> data) + " ";
            si.second += 1;
            if (currNode -> right != NULL)
                s.push({ currNode -> right, 1 });
        } else {
            postorder = postorder + to_string(currNode -> data) + " ";
            s.pop();
        }
    }

    cout << "pre -> " << preorder << endl;
    cout << "in -> " << inorder << endl;
    cout << "post -> " << postorder << endl;
}

int main() {
    TreeNode *root = takeInput();
    // printTree(root);
    // PrintTreeClean(root);
    PrePostInorder(root);

    return 0;
}