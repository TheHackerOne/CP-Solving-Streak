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

void printTree(BinaryTreeNode *root) {
    queue<BinaryTreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode *curr = q.front();
        q.pop();
        cout << curr -> data << " : ";
        if (curr -> left != NULL) {
            cout << "L " << curr -> left -> data << " ";
            q.push(curr -> left);
        }
        if (curr -> right != NULL) {
            cout << "R " << curr -> right -> data;
            q.push(curr -> right);
        }
        cout << endl;
    }
}

int mm[2] = {0, 0};

void widthOfBT(BinaryTreeNode *root, int hl) {
    if (root == NULL) return;

    mm[0] = min(mm[0], hl);
    mm[1] = max(mm[1], hl);
    widthOfBT(root -> left, hl - 1);
    widthOfBT(root -> right, hl + 1);
}

map<int, multiset<pair<int, int>>> mp;

void verticalOrderTraversal(BinaryTreeNode *root, int hl) {
    queue<pair<BinaryTreeNode *, int>> q;
    q.push({ root, hl });
    int level = 1;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            pair<BinaryTreeNode *, int> curr = q.front();
            q.pop();
            int hl = curr.second;
            mp[hl].insert({ level, curr.first -> data });
            if (curr.first -> left != NULL) {
                q.push({ curr.first -> left, hl - 1 });
            }
            if (curr.first -> right != NULL) {
                q.push({ curr.first -> right, hl + 1 });
            }
        }
        level++;
    }
}

int main() {
    BinaryTreeNode *root = TakeInput();
    widthOfBT(root, 0);
    int width = mm[1] - mm[0] + 1;
    verticalOrderTraversal(root, abs(mm[0]));
    for (auto list : mp) {
        cout << list.first << " : ";
        for (auto l : list.second)
            cout << l.second << " ";
        cout << endl;
    }

    return 0;
}