#include<bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k) {
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[arr[i]]++;
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != (k - arr[i]))
			count += (mp[k - arr[i]]);
		else count += (mp[k - arr[i]] - 1);
	}
	return count / 2;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		cout << getPairsCount(a, n, k);
	}

	return 0;
}