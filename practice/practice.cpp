#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = right = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

BinaryTreeNode *TakeInput() {
    int data;
    cin >> data;
    BinaryTreeNode *root = new BinaryTreeNode(data);
    queue<BinaryTreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode *curr = q.front();
        q.pop();
        int left;
        cout << "Enter the left child of " << curr -> data << endl;
        cin >> left;
        if (left != INT_MAX) {
            BinaryTreeNode *newNode = new BinaryTreeNode(left);
            curr -> left = newNode;
            q.push(newNode);
        }
        int right;
        cout << "Enter the right child of " << curr -> data << endl;
        cin >> right;
        if (right != INT_MAX) {
            BinaryTreeNode *newNode = new BinaryTreeNode(right);
            curr -> right = newNode;
            q.push(newNode);
        }
    }
    return root;
}

// void printTree(BinaryTreeNode *root) {
//     queue<BinaryTreeNode *> q;
//     q.push(root);
//     while (!q.empty()) {
//         BinaryTreeNode *curr = q.front();
//         q.pop();
//         cout << curr -> data << " : ";
//         if (curr -> left != NULL) {
//             cout << "L " << curr -> left -> data << " ";
//             q.push(curr -> left);
//         }
//         if (curr -> right != NULL) {
//             cout << "R " << curr -> right -> data;
//             q.push(curr -> right);
//         }
//         cout << endl;
//     }
// }

map<int, int> freq;


int pathSum(BinaryTreeNode *root, int currSum, int targetSum) {
    if (root == NULL) return 0;
    int count = 0;
    currSum += root -> data;
    if (freq[currSum - targetSum])
        count++;
    freq[currSum]++;
    int p1 = pathSum(root -> left, currSum, targetSum);
    int p2 = pathSum(root -> right, currSum, targetSum);
    freq[currSum]--;
    return p1 + p2 + count;
}

int main() {
    int targetSum;
    cin >> targetSum;
    BinaryTreeNode *root = TakeInput();
    freq[0] = 1;
    cout << "no of halo paths = " << pathSum(root, 0, targetSum) << endl;

    return 0;
}