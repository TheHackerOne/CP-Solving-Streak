#include<bits/stdc++.h>
using namespace std;

int subsetSum(int * arr, int n, int s) {
  if (s == 0) return 1;
  if (n == 0) return 0;

  if (arr[n - 1] > s)
    return subsetSum(arr, n - 1, s);
  else
    return subsetSum(arr, n - 1, s) + subsetSum(arr, n - 1, s - arr[n - 1]);
}

int main() {
  int n, s;
  cin >> n >> s;

  int arr[n];

  for (int i = 0; i < n; i++) cin >> arr[i];

  cout << subsetSum(arr, n , s);


  return 0;
}