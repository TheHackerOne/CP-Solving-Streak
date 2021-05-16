#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int dp[N][N];
int dpTable[N][N];
// Unbounded Knapsack
int dpPro(int *w, int *v, int size, int S) {
	for (int j = 1; j <= size; j++) {
		for (int i = 1; i <= S; i++) {
			if (w[j - 1] <= S) dpTable[j][i] = max(dpTable[j - 1][i], v[size - 1] + dpTable[j][i - w[j - 1]]);
			else dpTable[j][i] = dpTable[j - 1][i];
		}
	}
	return dp[size][S];
}

int memoized(int *w, int *v, int size, int S) {
	if (S == 0 || size == 0) return 0;
	if (dp[size][S] != -1) return dp[size][S];
	if (w[size - 1] <= S) {
		return dp[size][S] = max(memoized(w, v, size - 1, S), v[size - 1] + memoized(w, v, size, S - w[size - 1]));
	}
	return dp[size][S] = memoized(w, v, size - 1, S);
}

int UKnapsackRecursion(int *weight, int *value, int size, int S) {
	if (S == 0 || size == 0) return 0;
	if (weight[size - 1] <= S) {
		return max(UKnapsackRecursion(weight, value, size - 1, S), value[size - 1] + UKnapsackRecursion(weight, value, size, S - weight[size - 1]));
	}
	return UKnapsackRecursion(weight, value, size - 1, S);
}


int main() {
	int n, S;
	cin >> n >> S;
	memset(dp, -1, sizeof dp);
	memset(dpTable, 0, sizeof dpTable);

	int weight[n], value[n];
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}

	cout << UKnapsackRecursion(weight, value, n, S) << endl;
	cout << memoized(weight, value, n, S) << endl;
	cout << dpPro(weight, value, n, S) << endl;

	return 0;
}