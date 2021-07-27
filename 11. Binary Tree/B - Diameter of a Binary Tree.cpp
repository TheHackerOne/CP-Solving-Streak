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

pair<int, int> diameterOfBTHelper(TreeNode *root) {
    if (root == NULL) return { 0, 0 };

    if (root -> left == NULL && root -> right == NULL) return { 0, 0 };

    pair<int, int> leftAns = diameterOfBTHelper(root -> left);
    pair<int, int> rightAns = diameterOfBTHelper(root -> right);

    pair<int, int> ans;


    int rootDiameter = (root -> left ? left.first + 1 : 0) + (root -> right ? rightAns.first + 1 : 0);
    ans.first = max(leftAns.first, rightAns.first) + 1;
    ans.second = max(rootDiameter , max(leftAns.second, rightAns.second));

    return ans;
}

int diameterOfBT(TreeNode *root) {
    // max height, diameter
    pair<int, int> ans = diameterOfBTHelper(root);
    return ans.second;
}

int main() {
    TreeNode *root = takeInput();

    cout << diameterOfBT(root);

    return 0;
}