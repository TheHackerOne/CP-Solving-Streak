#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int dp[N][N];
int dpTable[N][N];

int dpMethod(int *a, int size, int sum) {
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j == 0) dp[i][j] = 1;
			else if (i == 0) dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= sum; j++) {
			if (a[i - 1] <= j) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
			else dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[size][sum];
}

int memoizeCountSubsetSums(int *a, int size, int sum) {
	// base condition
	if (sum == 0) return 1;
	if (size == 0) return 0;
	if (dp[size][sum] != -1)
		return dp[size][sum];
	if (a[size - 1] <= sum) {
		dp[size][sum] = memoizeCountSubsetSums(a, size - 1, sum) + memoizeCountSubsetSums(a, size - 1, sum - a[size - 1]);
	} else {
		dp[size][sum] = memoizeCountSubsetSums(a, size - 1, sum);
	}
	return dp[size][sum];
}

int countSubsetSums(int *a, int size, int sum) {
	// base condition
	if (sum == 0) return 1;
	if (size == 0) return 0;
	int subsetCount = 0;
	if (a[size - 1] <= sum) {
		subsetCount = countSubsetSums(a, size - 1, sum) + countSubsetSums(a, size - 1, sum - a[size - 1]);
	} else {
		subsetCount = countSubsetSums(a, size - 1, sum);
	}
	return subsetCount;
}

int main() {

	int n, S;
	cin >> n >> S;
	int a[n];
	memset(dp, -1, sizeof(dp));
	memset(dpTable, -1, sizeof(dp));

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << countSubsetSums(a, n, S) << endl;
	cout << memoizeCountSubsetSums(a, n, S) << endl;
	cout << dpMethod(a, n, S) << endl;


	return 0;
}