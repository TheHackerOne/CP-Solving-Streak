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

int PathSum1(BinaryTreeNode *root, int currSum, int targetSum) {
    if (root == NULL)
        return 0;
    currSum += root -> data;
    int count = 0;
    if (currSum == targetSum)
        count = 1;
    int res1 = PathSum1(root -> left, currSum, targetSum);
    int res2 = PathSum1(root -> right, currSum, targetSum);
    return count + res1 + res2;
}

int PathSum(BinaryTreeNode *root, int targetSum) {
    if (root == NULL)
        return 0;
    int res1 = PathSum1(root, 0, targetSum);
    int res2 = PathSum(root -> left, targetSum);
    int res3 = PathSum(root -> right, targetSum);
    return res1 + res2 + res3;
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

int main() {
    BinaryTreeNode *root = TakeInput();
    // printTree(root);
    cout << PathSum(root, 8) << endl;

    return 0;
}