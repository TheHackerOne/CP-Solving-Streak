#include<bits/stdc++.h>
using namespace std;

int mcm(int *arr, int l, int r) {

  if (l >= r) return 0;

  int ans = INT_MAX;
  for (int k = l ; k < r; k++) {
    ans = min(ans, mcm(arr, l, k) + mcm(arr, k + 1, r) + arr[l - 1] * arr[k] * arr[r]);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) cin >> arr[i];

  cout << mcm(arr, 1, n - 1);

  return 0;
}