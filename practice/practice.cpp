#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int dp[N][N];
int dpTable[N][N];
// Rod cutting problem
int dpPro(int *l, int size, int S) {
	for (int j = 1; j <= size; j++) {
		for (int i = 1; i <= S; i++) {
			if (l[j - 1] <= S) dpTable[j][i] = dpTable[j - 1][i] + dpTable[j][i - l[j - 1]];
			else dpTable[j][i] = dpTable[j - 1][i];
		}
	}
	return dp[size][S];
}

int memoized(int *coins, int size, int S) {
	if (S == 0) return 1;
	if (size == 0) return 0;
	if (dp[size][S] != -1) return dp[size][S];
	if (coins [size - 1] <= S) {
		return dp[size][S] = memoized(coins , size - 1, S) + memoized(coins, size, S - coins [size - 1]);
	}
	return dp[size][S] = memoized(coins , size - 1, S);
}

int coinChangeMaxWays(int *coins, int size, int S) {
	if (S == 0) return 1;
	if (size == 0) return 0;
	if (coins[size - 1] <= S)
		return coinChangeMaxWays(coins, size - 1, S) + coinChangeMaxWays(coins, size, S - coins[size - 1]);

	return coinChangeMaxWays(coins, size - 1, S);
}


int main() {
	int n, S;
	cin >> n >> S;
	memset(dp, -1, sizeof dp);
	memset(dpTable, 0, sizeof dpTable);

	int coins[n];
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	cout << coinChangeMaxWays(coins, n, S) << endl;
	cout << memoized(coins, n, S) << endl;
	cout << dpPro(coins, n, S) << endl;

	return 0;
}