#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode *TakeInput() {
    int data;
    cout << "Enter root data" << endl;
    cin >> data;
    BinaryTreeNode *root = new BinaryTreeNode(data);
    queue<BinaryTreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        BinaryTreeNode *curr = pendingNodes.front();
        pendingNodes.pop();
        int left;
        // cout << "Enter the left child " << endl;
        cin >> left;
        if (left != -1) {
            BinaryTreeNode *newNode = new BinaryTreeNode(left);
            curr -> left = newNode;
            pendingNodes.push(newNode);
        }
        int right;
        // cout << "Enter the right child " << endl;
        cin >> right;
        if (right != -1) {
            BinaryTreeNode *newNode = new BinaryTreeNode(right);
            curr -> right = newNode;
            pendingNodes.push(newNode);
        }
    }
    return root;
}

void printTree(BinaryTreeNode *root) {
    if (root == NULL)
        return;
    cout << root -> data << " : ";
    if (root -> left != NULL)
        cout << root -> left -> data << " ";
    if (root -> right != NULL)
        cout << root -> right -> data;
    cout << endl;
    printTree(root -> left);
    printTree(root -> right);
}

void PrintLevelOrder(BinaryTreeNode *root) {
    queue<BinaryTreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        BinaryTreeNode *curr = pendingNodes.front();
        pendingNodes.pop();
        cout << curr -> data << " : ";
        if (curr -> left != NULL) {
            cout << " L" << curr -> left -> data << " ";
            pendingNodes.push(curr -> left);
        }
        if (curr -> right != NULL) {
            cout << " R" << curr -> right -> data << " ";
            pendingNodes.push(curr -> right);
        }
        cout << endl;
    }
}

void printLeftView(BinaryTreeNode *root) {
    queue<BinaryTreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        int size = pendingNodes.size();
        cout << pendingNodes.front() -> data << endl;
        while (size--) {
            BinaryTreeNode *curr = pendingNodes.front();
            pendingNodes.pop();
            if (curr -> left != NULL) pendingNodes.push(curr -> left);
            if (curr -> right != NULL) pendingNodes.push(curr -> right);
        }
    }
}

int main() {
    BinaryTreeNode *root = TakeInput();
    // PrintLevelOrder(root);
    cout << endl;
    cout << "Left View of Binary tree" << endl;
    printLeftView(root);

    return 0;
}