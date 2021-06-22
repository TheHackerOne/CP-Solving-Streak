#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int max;
    int smax;
};

void updateTree(int *arr, Node *tree, int treeNode, int start, int end, int val, int idx) {
    if (start == end) {
        tree[treeNode].max = val;
        arr[idx] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx > mid) {
        updateTree(arr, tree, 2 * treeNode + 1, mid + 1, end, val, idx);
    } else {
        updateTree(arr, tree, 2 * treeNode, start, mid, val, idx);
    }
    tree[treeNode].max = max(tree[2 * treeNode].max, tree[2 * treeNode + 1].max);
    tree[treeNode].smax = min(max(tree[2 * treeNode].smax, tree[2 * treeNode + 1].max),
                              max(tree[2 * treeNode].max, tree[2 * treeNode + 1].smax));
}

Node query(int *arr, Node *tree, int treeNode, int start, int end, int left, int right) {
    if (left > end || right < start) {
        Node res;
        res.max = 0, res.smax = 0;
        return res;
    }

    if (left <= start && right >= end) return tree[treeNode];
    int mid = (start + end) / 2;
    Node leftRes = query(arr, tree, 2 * treeNode, start, mid, left, right);
    Node rightRes = query(arr, tree, 2 * treeNode + 1, mid + 1, end, left, right);
    Node maxSmax;
    maxSmax.max = max(leftRes.max, rightRes.max);
    maxSmax.smax = min(max(leftRes.smax, rightRes.max),
                       max(leftRes.max, rightRes.smax));
    return maxSmax;
}

void buildTree(int *arr, Node *tree, int treeNode, int start, int end) {
    if (start == end) {
        tree[treeNode].max = arr[start];
        tree[treeNode].smax = INT_MIN;
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, 2 * treeNode, start, mid);
    buildTree(arr, tree, 2 * treeNode + 1, mid + 1, end);
    tree[treeNode].max = max(tree[2 * treeNode].max, tree[2 * treeNode + 1].max);
    tree[treeNode].smax = min(max(tree[2 * treeNode].smax, tree[2 * treeNode + 1].max),
                              max(tree[2 * treeNode].max, tree[2 * treeNode + 1].smax));
}

// void printTree(int *tree) {
//     for (int i = 1; i < 4 * n; i++) cout << tree[i] << " ";
//     cout << endl;
// }

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Node *tree = new Node[4 * n];

    // Build Tree
    buildTree(arr, tree, 1, 0, n - 1);

    // printTree(tree);

    // Query the Tree
    Node res = query(arr, tree, 1, 0, n - 1, 2, 5);
    cout << res.max << " " << res.smax << endl;

    // Update the Tree
    updateTree(arr, tree, 1, 0, n - 1, 34, 2);

    // printTree(tree);

    // Query the Tree
    Node res1 = query(arr, tree, 1, 0, n - 1, 2, 5);
    cout << res1.max << " " << res1.smax << endl;

    return 0;
}