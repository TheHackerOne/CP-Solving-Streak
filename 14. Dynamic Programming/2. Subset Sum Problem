#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int dp[N][N];
int dpTable[N][N];

bool dpSubset(int *a, int size, int sum) {
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

bool memoizedSubsetSum(int *a, int size, int sum) {
	if (sum == 0) return true;
	if (size == 0) return false;
	if (dp[size][sum] != -1)
		return dp[size][sum];
	if (a[size - 1] <= sum) {
		return dp[size][sum] = memoizedSubsetSum(a, size - 1, sum - a[size - 1]) || memoizedSubsetSum(a, size - 1, sum);
	} else {
		return dp[size][sum] = memoizedSubsetSum(a, size - 1, sum);
	}
}

bool subsetSumRecursion(int *a, int size, int sum) {
	if ((size == 0 && sum == 0) || (size != 0 && sum == 0)) return true;
	if (size == 0) return false;

	if (a[size - 1] <= sum) {
		return subsetSumRecursion(a, size - 1, sum - a[size - 1]) || subsetSumRecursion(a, size - 1, sum);
	} else {
		return subsetSumRecursion(a, size - 1, sum);
	}
}

int main() {

	int n, S;
	cin >> n >> S;
	int a[n];
	memset(dp, -1, sizeof(dp));
	memset(dpTable, -1, sizeof(dp));

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << subsetSumRecursion(a, n, S) << endl;
	cout << memoizedSubsetSum(a, n, S) << endl;
	cout << dpSubset(a, n, S) << endl;

	return 0;
}