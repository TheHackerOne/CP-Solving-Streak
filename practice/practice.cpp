#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int dp[N][N];
int dpTable[N][N];

void dpSubset(int *a, int size, int sum) {
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
}

int minSubsetSumDiff(int *a, int size, int sum) {
	dpSubset(a, size, sum);
	int avalaibleRange[sum + 1];
	for (int i = 0; i <= sum; i++)
		avalaibleRange[i] = dpTable[size][i];
	int minimum = INT_MAX;
	for (int i = 0; i <= sum / 2; i++) {
		if (avalaibleRange[i] == 1) {
			int m = sum - (2 * i);
			minimum = min(minimum, m);
		}
	}
	return minimum;
}

int main() {

	int n, S = 0 ;
	cin >> n;
	int a[n];
	memset(dp, -1, sizeof(dp));
	memset(dpTable, -1, sizeof(dp));

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		S += a[i];
	}

	cout << minSubsetSumDiff(a, n, S) << endl;


	return 0;
}