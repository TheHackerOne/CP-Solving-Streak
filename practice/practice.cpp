#include<bits/stdc++.h>
using namespace std;

string lcs(string a, int al, string b, int bl) {
  int dp[al + 1][bl + 1];
  for (int i = 0; i <= al; i++) {
    for (int j = 0; j <= bl; j++) {
      dp[i][j] = 0;
    }
  }

  for (int i = 1; i <= al; i++) {
    for (int j = 1; j <= bl; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }
  int i = al, j = bl;
  string ans = "";
  while (i > 0 && j > 0) {
    if (a[i - 1] == b[j - 1]) {
      ans.push_back(a[i - 1]);
      i--;
      j--;
    } else {
      if (dp[i][j - 1] > dp[i - 1][j]) {
        ans.push_back(b[j - 1]);
        j--;
      } else {
        ans.push_back(a[i - 1]);
        i--;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  string a, b;
  cin >> a >> b;

  cout << lcs(a, a.length(), b, b.length());

  return 0;
}