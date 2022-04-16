#include<bits/stdc++.h>
using namespace std;

void makeTree(vector<int> &arr, vector<int> &tree, int treeIdx, int left, int right){
    // base case
    if(left > right) return;
    if(left == right){
        tree[treeIdx] = arr[left];
        return;
    }

    // main logic
    int mid = (left+right)/2;
    makeTree(arr, tree, 2*treeIdx, left, mid);
    makeTree(arr, tree, 2*treeIdx+1, mid+1, right);
    tree[treeIdx] = tree[2*treeIdx]+tree[2*treeIdx+1];
}

int query(vector<int> &tree, int left, int right, int treeIdx, int lo, int hi){
    // base case
    if(lo > right or hi < left) return 0;
    if(lo <= left and hi >= right) return tree[treeIdx];

    // main logic
    int mid = (left + right)/2;
    int leftRes = query(tree, left, mid, 2*treeIdx, lo, hi);
    int rightRes = query(tree, mid+1, right, 2*treeIdx+1, lo, hi);
    return leftRes+rightRes;
}

void update(vector<int> &arr, vector<int> &tree, int treeIdx, int idx, int val, int left, int right){
    // base case
    if(left == right){
        arr[left] = val;
        tree[treeIdx] = val;
        return;
    }

    // main logic
    int mid = (left+right)/2;
    if(idx <= mid)
        update(arr, tree, 2*treeIdx, idx, val, left, mid);
    else
        update(arr, tree, 2*treeIdx+1, idx, val, mid+1, right);
    tree[treeIdx] = tree[2*treeIdx]+tree[2*treeIdx+1];
}

int main(){
    // query and update
    // prefix sum -> query = O(1), update = O(n)
    // normal array -> query = O(n), update = O(1);
    // segment tree -> query = O(log n), update = O(log n)

    // array as input
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> tree(4*n);

    // make a tree
    makeTree(arr, tree, 1, 0, n-1);

    // query 
    cout<<query(tree, 0, n-1, 1, 1, 3);

    // update
    update(arr, tree, 1, 3, 10, 0, n-1);

    cout<<query(tree, 0, n-1, 1, 1, 3);


    return 0;
}