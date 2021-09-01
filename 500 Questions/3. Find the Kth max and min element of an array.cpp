#include<bits/stdc++.h>
using namespace std;

int kthMin(int *a, int k, int n) {
	priority_queue<int> maxheap;
	for (int i = 0; i < n; i++) {
		maxheap.push(a[i]);
		if (maxheap.size() > k) {
			maxheap.pop();
		}
	}
	return maxheap.top();
}

int kthMax(int *a, int k, int n) {
	priority_queue<int, vector<int>, greater<int>> minheap;
	for (int i = 0; i < n; i++) {
		minheap.push(a[i]);
		if (minheap.size() > k) {
			minheap.pop();
		}
	}
	return minheap.top();
}

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << "Kth Max  = " << kthMax(a, k, n) << endl;
	cout << "Kth Min = " << kthMin(a, k, n) << endl;


	return 0;
}