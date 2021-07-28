#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int *arr, int l, int h, int val) {
  while (l <= h) {
    int mid = (l + h) / 2;
    if (arr[mid] == val) {
      return true;
    } else if (arr[mid] > val) {
      h = mid - 1 ;
    } else {
      l = mid + 1;
    }
  }
  return false;
}

int findX(int *arr, int l, int h) {
  while (l <= h) {
    int mid = (l + h) / 2;
    if (arr[mid] > arr[mid + 1]) {
      return mid;
    } else if (arr[mid] > h) {
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  return -1;
}

int main() {
  int n, val;
  cin >> n >> val;

  int arr[n];

  for (int i = 0; i < n; i++) cin >> arr[i];

  int idx = findX(arr, 0, n - 1);

  if (binarySearch(arr, 0, idx, val) || binarySearch(arr, idx + 1, n - 1, val))
    cout << "value present";
  else
    cout << "value not present";

  return 0;
}