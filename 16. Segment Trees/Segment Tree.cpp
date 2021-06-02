#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int *tree, int treeNode, int s, int e) {
    if (s == e) {
        tree[treeNode] = arr[s];
        return;
    }

    int mid = (s + e) / 2;
    buildTree(arr, tree, 2 * treeNode, s, mid);
    buildTree(arr, tree, 2 * treeNode + 1, mid + 1, e);
    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

// We will always update the leaf node which in turn changes the sums in
// middle nodes and root node
void updateTree(int *arr, int *tree, int treeNode, int s, int e, int idx, int value) {
    if (s == e) {
        arr[idx] = value;
        tree[treeNode] = value;
        return;
    }

    int mid = (s + e) / 2;
    if (idx > mid) {
        updateTree(arr, tree, 2 * treeNode + 1, mid + 1, e, idx, value);
    } else {
        updateTree(arr, tree, 2 * treeNode, s, mid, idx, value);
    }
    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

int query(int *tree, int treeNode, int s, int e, int left, int right) {
    // completely outside the given range
    if (left > e || right < s) {
        return 0;
    }

    // completely inside the given range
    if (left <= s && right >= e) {
        return tree[treeNode];
    }

    //partially inside and partially outside
    int mid = (s + e) / 2;
    int ans1 = query(tree, 2 * treeNode, s, mid, left, right);
    int ans2 = query(tree, 2 * treeNode + 1, mid + 1, e, left, right);
    return ans1 + ans2;
}

void printArray(int *arr, int n) {
    cout << "array ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

void printTree(int *tree, int n) {
    cout << "Tree  ";
    for (int i = 1; i < 2 * n; i++)
        cout << tree[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int tree[2 * n];
    buildTree(arr, tree, 1, 0, n - 1);

    printArray(arr, n);
    printTree(tree, n);

    updateTree(arr, tree, 1, 0, n - 1, 2, 12);

    printArray(arr, n);
    printTree(tree, n);

    cout << "Query = " << query(tree, 1, 0, n - 1, 0, 3);

    return 0;
}