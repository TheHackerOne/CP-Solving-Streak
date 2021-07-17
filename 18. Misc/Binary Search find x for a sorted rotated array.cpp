#include<bits/stdc++.h>
using namespace std;

// you are given a sorted array (asc) which is rotated to the left x times, find x

int findX(int *arr, int l, int h) {
  while (l <= h) {
    int mid = (l + h) / 2;
    if (arr[mid] > arr[mid + 1]) {
      return mid;
    } else if (arr[mid] < h) {
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) cin >> arr[i];

  int idx = findX(arr, 0, n - 1);

  cout << n - idx - 1 << endl;

  return 0;
}