#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int dp[N][N];
int dpTable[N][N];

int dpPro(int *coins, int size, int S) {
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= S; j++) {
			if (j == 0) dpTable[i][j] = 0;
			else dpTable[i][j] = INT_MAX - 1;
		}
	}
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= S; j++) {
			if (coins[i - 1] <= S)
				dpTable[i][j] = min(dpTable[i - 1][j], 1 + dpTable[i][j - coins[i - 1]]);
			else
				dpTable[i][j] = dpTable[i - 1][j];
		}
	}
	return dpTable[size][S];
}

int memoized(int *coins, int size, int S) {
	if (S == 0) return 0;
	if (size == 0) return INT_MAX;
	if (dp[size][S] != -1) return dp[size][S];
	if (coins[size - 1] <= S) {
		int min1 = memoized(coins, size - 1, S);
		int min2 = memoized(coins, size, S - coins[size - 1]);
		if (min2 == INT_MAX)  min2--;
		return dp[size][S] = min(min1, 1 + min2);
	}
	return dp[size][S] = memoized(coins, size - 1, S);
}

int coinChangeMinCoins(int *coins, int size, int S) {
	if (S == 0) return 0;
	if (size == 0) return INT_MAX;
	if (coins[size - 1] <= S) {
		int min1 = coinChangeMinCoins(coins, size - 1, S);
		int min2 = coinChangeMinCoins(coins, size, S - coins[size - 1]);
		if (min2 == INT_MAX)  min2--;
		return min(min1, 1 + min2);
	}
	return coinChangeMinCoins(coins, size - 1, S);
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

	cout << coinChangeMinCoins(coins, n, S) << endl;
	cout << memoized(coins, n, S) << endl;
	cout << dpPro(coins, n, S) << endl;

	return 0;
}