#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int l, int r) {
  string g = s.substr(l, r + 1);
  // if (l == 5 && r == 8)
  //   cout << l << " -> " << r << " = " << g << endl;
  int size = s.length();
  int i = 0, j = r - l;
  bool flag = true;
  while (i <= j) {
    if (g[i] == g[j]) {
      i++, j--;
    } else {
      flag = false;
      break;
    }
  }
  // if (l == 5 && r == 8)
  //   cout << "result -> " << flag << endl;
  return flag ? true : false;
}

int mcm(string arr, int l, int r) {

  if (l >= r) return 0;

  if (isPalindrome(arr, l, r)) return 0;

  int ans = INT_MAX;
  for (int k = l ; k < r; k++) {
    if (k == 4 && l == 0 && r == 8) {
      int s1 = mcm(arr, l, k);
      int s2 = mcm(arr, k + 1, r);
    }
    ans = min(ans, mcm(arr, l, k) + mcm(arr, k + 1, r) + 1);
  }
  return ans;
}

int main() {
  string s;
  cin >> s;

  cout << mcm(s, 0, s.length() - 1);
  // cout << isPalindrome(s, 0, s.length() - 1);

  return 0;
}