// #include<bits/stdc++.h>
// using namespace std;

// class TreeNode {
// public:
//     int data;
//     TreeNode *left;
//     TreeNode *right;

//     TreeNode(int data) {
//         this -> data = data;
//         left = right = NULL;
//     }
// };

// class pairNode {
// public:
//     int max;
//     int min;
//     int size;
//     bool isBST;
// };



// TreeNode* takeInput() {
//     int data;
//     cin >> data;
//     TreeNode *root = new TreeNode(data);
//     queue<TreeNode *> q;
//     q.push(root);
//     while (!q.empty()) {
//         TreeNode *front = q.front();
//         q.pop();
//         int left;
//         cin >> left;
//         if (left != -1) {
//             TreeNode *newNode = new TreeNode(left);
//             front -> left = newNode;
//             q.push(newNode);
//         }
//         int right;
//         cin >> right;
//         if (right != -1) {
//             TreeNode *newNode = new TreeNode(right);
//             front -> right = newNode;
//             q.push(newNode);
//         }
//     }
//     return root;
// }

// void printTree(TreeNode *root) {
//     if (root == NULL) return;

//     cout << root -> data << endl;

//     printTree(root -> left);
//     printTree(root -> right);
// }

// void PrintTreeClean(TreeNode *root) {
//     queue<TreeNode *> q;
//     q.push(root);
//     while (!q.empty()) {
//         TreeNode *front = q.front();
//         q.pop();
//         cout << front -> data << " : ";
//         if (front -> left != NULL) {
//             cout << front -> left -> data << " ";
//             q.push(front -> left);
//         }
//         if (front -> right != NULL) {
//             cout << front -> right -> data << " ";
//             q.push(front -> right);
//         }
//         cout << endl;
//     }
// }



// pairNode largestBstHelper(TreeNode *root) {
//     if (root == NULL) {
//         pairNode ans;
//         ans.min = INT_MAX;
//         ans.max = INT_MIN;
//         ans.size = 0;
//         ans.isBST = true;
//         return ans;
//     }

//     pairNode left = largestBstHelper(root -> left);
//     pairNode right = largestBstHelper(root -> right);

//     pairNode ans;
//     ans.isBST = (left.isBST && right.isBST && root -> data < right.min && root -> data > left.max ) ? true : false;
//     ans.min = min(root -> data, min(left.min, right.min));
//     ans.max = max(root -> data, max(left.max, right.max));
//     if (ans.isBST) {
//         ans.size = left.size + right.size + 1;
//     } else {
//         ans.size = max(left.size, right.size);
//     }

//     return ans;
// }




// int largestBst(TreeNode *root)
// {
//     pairNode ans = largestBstHelper(root);
//     return ans.size;
// }

// int main() {
//     TreeNode *root = takeInput();

//     int ans =  largestBst(root);
//     cout << ans;

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << (1 || 0 || 0 );

    return 0;
}