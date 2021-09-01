#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {

	// Your code here
	long long maxSum = INT_MIN, sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		maxSum = max(maxSum, sum);
		if (sum < 0) {
			sum = 0;
		}
	}
	return maxSum;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << maxSubarraySum(a, n);

	return 0;
}