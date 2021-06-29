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
	tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
}

void updateSegmentTreeLazy(int *tree, int *lazy, int currPos, int l, int h, int s, int e, int inc) {
	if (l > h) return;
	if (lazy[currPos] != 0) {
		tree[currPos] += lazy[currPos];
		if (l != h) {
			lazy[2 * currPos] += lazy[currPos];
			lazy[2 * currPos + 1] += lazy[currPos];
		}
		lazy[currPos] = 0;
	}

	// for completely outside
	if (s > h || e < l) return;

	// for completely inside
	if (s <= l && e >= h) {
		tree[currPos] += inc;
		if (l != h) {
			lazy[2 * currPos] += inc;
			lazy[2 * currPos + 1] += inc;
		}
		return;
	}

	// for partial overlap
	int mid = (l + h) / 2;
	updateSegmentTreeLazy(tree, lazy, 2 * currPos, l, mid, s, e, inc);
	updateSegmentTreeLazy(tree, lazy, 2 * currPos + 1, mid + 1, h, s, e, inc);
	tree[currPos] = min(tree[2 * currPos], tree[2 * currPos + 1]);
}

int main() {
	int arr[] = {1, 3, -2, 4};
	int tree[13], lazy[13];

	for (int i = 0; i < 13; i++) tree[i] = 0, lazy[i] = 0;

	buildTree(arr, tree, 1, 0, 3);

	updateSegmentTreeLazy(tree, lazy, 1, 0, 3, 0, 3, 3);
	updateSegmentTreeLazy(tree, lazy, 1, 0, 3, 0, 1, 2);

	cout << "Segment tree" << endl;
	for (int i = 1; i <= 12; i++) cout << tree[i] << endl;
	cout << "Lazy tree" << endl;
	for (int i = 1; i <= 12; i++) cout << lazy[i] << endl;

	return 0;
}