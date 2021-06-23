#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int maxSum;
    int BPrefixSum;
    int BSuffixSum;
    int sum;
};

void updateTree(int *arr, Node *tree, int treeNode, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[treeNode].maxSum = val;
        tree[treeNode].sum = val;
        tree[treeNode].BPrefixSum = val;
        tree[treeNode].BSuffixSum = val;
        return;
    }

    int mid = (start + end) / 2;
    if (idx > mid) {
        updateTree(arr, tree, 2 * treeNode + 1, mid + 1, end, idx, val);
    } else {
        updateTree(arr, tree, 2 * treeNode, start, mid, idx, val);
    }

    int Lmax = tree[2 * treeNode].maxSum;
    int Rmax = tree[2 * treeNode + 1].maxSum;
    int LBS = tree[2 * treeNode].BSuffixSum;
    int LBP = tree[2 * treeNode].BPrefixSum;
    int RBP = tree[2 * treeNode + 1].BPrefixSum;
    int RBS = tree[2 * treeNode + 1].BSuffixSum;
    int Lsum = tree[2 * treeNode].sum;
    int Rsum = tree[2 * treeNode + 1].sum;

    tree[treeNode].maxSum = max(Lmax, max(Rmax, max(LBS + RBP, max(Lsum + RBP, Rsum + LBS))));
    tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
    tree[treeNode].BPrefixSum = max(LBP, Lsum + RBP);
    tree[treeNode].BSuffixSum = max(RBS, Rsum + LBS);

}

void buildTree(int *arr, Node *tree, int treeNode, int start, int end) {
    if (start == end) {
        tree[treeNode].maxSum = arr[start];
        tree[treeNode].sum = arr[start];
        tree[treeNode].BPrefixSum = arr[start];
        tree[treeNode].BSuffixSum = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, 2 * treeNode, start, mid);
    buildTree(arr, tree, 2 * treeNode + 1, mid + 1, end);

    int Lmax = tree[2 * treeNode].maxSum;
    int Rmax = tree[2 * treeNode + 1].maxSum;
    int LBS = tree[2 * treeNode].BSuffixSum;
    int LBP = tree[2 * treeNode].BPrefixSum;
    int RBP = tree[2 * treeNode + 1].BPrefixSum;
    int RBS = tree[2 * treeNode + 1].BSuffixSum;
    int Lsum = tree[2 * treeNode].sum;
    int Rsum = tree[2 * treeNode + 1].sum;

    tree[treeNode].maxSum = max(Lmax, max(Rmax, max(LBS + RBP, max(Lsum + RBP, Rsum + LBS))));
    tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
    tree[treeNode].BPrefixSum = max(LBP, Lsum + RBP);
    tree[treeNode].BSuffixSum = max(RBS, Rsum + LBS);
}

void printTree(Node *tree, int n) {
    for (int i = 1; i < 3 * n; i++) {
        cout << "Sum : " << tree[i].sum << endl;
        cout << "maxSum : " << tree[i].maxSum << endl;
        cout << "PrefixSum : " << tree[i].BPrefixSum << endl;
        cout << "SuffixSum : " << tree[i].BSuffixSum << endl;
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *tree = new Node[4 * n];

    // Build Tree
    buildTree(arr, tree, 1, 0, n - 1);

    printTree(tree, n);

    // Update Tree
    int idx = 2;
    int val = -5;
    updateTree(arr, tree, 1, 0, n - 1, idx, val);

    printTree(tree, n);


    return 0;
}
