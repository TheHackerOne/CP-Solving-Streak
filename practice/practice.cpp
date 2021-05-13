#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int dp[N][N];
int dpTable[N][N];

int dpKnapsack(int *w, int *v, int size, int Capacity) {
	// initialization
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= Capacity; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
		}
	}

	// bottom up
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= Capacity; j++) {
			if (w[i - 1] <= j)
				dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[size][Capacity];
}

// top down
int memoizedKnapsack(int *w, int *v, int size, int Capacity) {
	if (size == 0 || Capacity == 0) {
		return 0;
	}
	if (dp[size][Capacity] != -1) {
		return dp[size][Capacity];
	}
	if (w[size - 1] <= Capacity) {
		return dp[size][Capacity] = max(v[size - 1] + memoizedKnapsack(w, v, size - 1, Capacity - w[size - 1]),
		                                memoizedKnapsack(w, v, size - 1, Capacity));
	} else {
		return dp[size][Capacity] = memoizedKnapsack(w, v, size - 1, Capacity);
	}
}

int RecursiveKnapsack(int *w, int *v, int size, int Capacity) {
	//base case
	if (size == 0 || Capacity == 0)
		return 0;

	//hypothesis and induction
	int maxProfit = INT_MIN;
	if (w[size - 1] <= Capacity) {
		maxProfit = max(v[size - 1] + RecursiveKnapsack(w, v, size - 1, Capacity - w[size - 1]),
		                RecursiveKnapsack(w, v, size - 1, Capacity));
	} else {
		maxProfit = RecursiveKnapsack(w, v, size - 1, Capacity);
	}
	return maxProfit;
}

int main() {
	int n, Capacity;
	cin >> n >> Capacity;
	memset(dp, -1, sizeof(dp));
	int weight[n], value[n];
	for (int i = 0; i < n; i++)
		cin >> weight[i];
	for (int i = 0; i < n; i++)
		cin >> value[i];
	cout << RecursiveKnapsack(weight, value, n, Capacity) << endl;
	cout << memoizedKnapsack(weight, value, n, Capacity) << endl;
	cout << dpKnapsack(weight, value, n, Capacity) << endl;

	return 0;
}
