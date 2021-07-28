#include<bits/stdc++.h>
using namespace std;

// Find frequency of a given number using binary search in log n

int upperBound(int *arr, int l, int h, int val) {
  int size = h - l;
  while (l <= h) {
    int mid = (l + h) / 2;
    cout << "mid -> " << mid << endl;
    if (arr[mid] == val) {
      if (arr[mid] == arr[mid + 1] && (mid + 1) <= size)
        l = mid + 1;
      else return mid;
    } else if (arr[mid] < val) {
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  return INT_MAX;
}

int lowerBound(int *arr, int l, int h, int val) {
  int size = h - l;
  while (l <= h) {
    int mid = (l + h) / 2;
    if (arr[mid] == val) {
      if (arr[mid] == arr[mid - 1] && (mid + 1) <= size)
        h = mid - 1;
      else return mid;
    } else if (arr[mid] < val) {
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  return INT_MAX;
}

int freqCount(int *arr, int val, int size) {
  int l = lowerBound(arr, 0, size - 1, val);
  int r = upperBound(arr, 0, size - 1, val);
  cout << l << " " << r << endl;

  if (l == INT_MAX && r == INT_MAX) return -1;
  return r - l + 1;
}

int main() {
  int n, val;
  cin >> n >> val;

  int arr[n];

  for (int i = 0; i < n; i++) cin >> arr[i];

  cout << freqCount(arr, val, 8);

  return 0;
}