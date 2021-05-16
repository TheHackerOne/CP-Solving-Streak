#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int dp[N][N];
int dpTable[N][N];
// Rod cutting problem
int dpPro(int *l, int *p, int size, int S) {
	for (int j = 1; j <= size; j++) {
		for (int i = 1; i <= S; i++) {
			if (l[j - 1] <= S) dpTable[j][i] = max(dpTable[j - 1][i], p[size - 1] + dpTable[j][i - l[j - 1]]);
			else dpTable[j][i] = dpTable[j - 1][i];
		}
	}
	return dp[size][S];
}

int memoized(int *l, int *p, int size, int S) {
	if (S == 0 || size == 0) return 0;
	if (dp[size][S] != -1) return dp[size][S];
	if (l[size - 1] <= S) {
		return dp[size][S] = max(memoized(l, p, size - 1, S), p[size - 1] + memoized(l, p, size, S - l[size - 1]));
	}
	return dp[size][S] = memoized(l, p, size - 1, S);
}

int rodCuttingProblem(int *length, int *price, int size, int S) {
	if (S == 0 || size == 0) return 0;
	if (length[size - 1] <= S) {
		return max(rodCuttingProblem(length, price, size - 1, S), price[size - 1] + rodCuttingProblem(length, price, size, S - length[size - 1]));
	}
	return rodCuttingProblem(length, price, size - 1, S);
}


int main() {
	int n, S;
	cin >> n >> S;
	memset(dp, -1, sizeof dp);
	memset(dpTable, 0, sizeof dpTable);

	int length[n], price[n];
	for (int i = 0; i < n; i++) {
		cin >> length[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}

	cout << rodCuttingProblem(length, price, n, S) << endl;
	cout << memoized(length, price, n, S) << endl;
	cout << dpPro(length, price, n, S) << endl;

	return 0;
}