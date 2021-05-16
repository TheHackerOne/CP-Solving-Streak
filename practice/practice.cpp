#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int dp[N][N];
int dpTable[N][N];

int dpro(string s1, int size1, string s2, int size2) {
	for (int i = 1; i <= size1; i++) {
		for (int j = 1; j <= size2; j++) {
			if (s1[i - 1] == s2[j - 1]) dpTable[i][j] = 1 + dpTable[i - 1][j - 1];
			else dpTable[i][j] = max(dpTable[i - 1][j], dpTable[i][j - 1]);
		}
	}
	for (int i = 1; i <= size1; i++) {
		for (int j = 1; j <= size2; j++) {
			cout << dpTable[i][j] << " ";
		}
		cout << endl;
	}
	return dpTable[size1][size2];
}

int memoized(string s1, int size1, string s2, int size2) {
	if (size1 == 0 || size2 == 0) return 0;
	if (dp[size1][size2] != -1) return dp[size1][size2];
	if (s1[size1 - 1] == s2[size2 - 1])
		return dp[size1][size2] = 1 + memoized(s1, size1 - 1, s2, size2 - 1);
	else
		return dp[size1][size2] = max(memoized(s1, size1 - 1, s2, size2), memoized(s1, size1, s2, size2 - 1));
}

int LCS(string s1, int size1, string s2, int size2) {
	if (size1 == 0 || size2 == 0) return 0;
	if (s1[size1 - 1] == s2[size2 - 1])
		return 1 + LCS(s1, size1 - 1, s2, size2 - 1);
	else
		return max(LCS(s1, size1 - 1, s2, size2), LCS(s1, size1, s2, size2 - 1));
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	memset(dp, -1, sizeof dp);

	cout << LCS(s1, s1.length(), s2, s2.length()) << endl;
	cout << memoized(s1, s1.length(), s2, s2.length()) << endl;
	cout << dpro(s1, s1.length(), s2, s2.length()) << endl;

	return 0;
}