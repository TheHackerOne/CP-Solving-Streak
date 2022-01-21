#include<bits/stdc++.h>
using namespace std;

void makeTree(vector<int> &arr, vector<int> &tree, int left, int right, int treeNode){
    if(left == right){
        tree[treeNode] = arr[left];
        return;
    }

    int mid = (left+right)/2;
    makeTree(arr, tree, left, mid, 2*treeNode);
    makeTree(arr, tree, mid+1, right, 2*treeNode+1);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> tree(4*n);

    makeTree(arr, tree, 0, n-1, 1);
    for(auto i:tree)cout<<i<<" ";
    updateTree();

    return 0;
}