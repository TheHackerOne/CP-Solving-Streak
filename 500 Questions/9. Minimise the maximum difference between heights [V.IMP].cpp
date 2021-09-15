#include<bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
	sort(arr, arr + n);
	int ans = arr[n - 1] - arr[0];
	int minEle, maxEle;
	for (int i = 1; i <= n - 1; i++) {
		if (arr[i] >= k) {
			minEle = min(arr[0] + k, arr[i] - k);
			maxEle = max(arr[i - 1] + k, arr[n - 1] - k);
			ans = min(ans, maxEle - minEle);
		}
	}
	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	cout << getMinDiff(arr, n, k) << endl;

	return 0;
}