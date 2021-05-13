#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int dp[N][N];
int dpTable[N][N];

bool dpEqualSum(int *a, int size, int sum) {
	//initialization
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j == 0) dpTable[i][j] = 1;
			else if (i == 0) dpTable[i][j] = 0;
		}
	}
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= sum; j++) {
			if (a[i - 1] <= j) dpTable[i][j] = dpTable[i - 1][j] || dpTable[i - 1][j - a[i - 1]];
			else dpTable[i][j] = dpTable[i - 1][j];
		}
	}
	return dpTable[size][sum];
}

bool memoizedEqualSum(int *a, int size, int sum) {
	if (sum == 0) return true;
	if (size == 0) return false;
	if (dp[size][sum] != -1)
		return dp[size][sum];
	if (a[size - 1] <= sum) {
		return dp[size][sum] = memoizedEqualSum(a, size - 1, sum - a[size - 1]) || memoizedEqualSum(a, size - 1, sum);
	} else {
		return dp[size][sum] = memoizedEqualSum(a, size - 1, sum);
	}
}

bool equalSumPartition(int *a, int size, int sum) {
	if ((size == 0 && sum == 0) || (size != 0 && sum == 0)) return true;
	if (size == 0) return false;

	if (a[size - 1] <= sum) {
		return equalSumPartition(a, size - 1, sum - a[size - 1]) || equalSumPartition(a, size - 1, sum);
	} else {
		return equalSumPartition(a, size - 1, sum);
	}
}

int main() {

	int n, S = 0;
	cin >> n ;
	int a[n];
	memset(dp, -1, sizeof(dp));
	memset(dpTable, -1, sizeof(dp));

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		S += a[i];
	}

	cout << S << endl;
	if ((S ^ 1) == 0) {
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
	} else {
		cout << equalSumPartition(a, n, S / 2) << endl;
		cout << memoizedEqualSum(a, n, S / 2) << endl;
		cout << dpEqualSum(a, n, S / 2) << endl;
	}


	return 0;
}