#include<bits/stdc++.h>
using namespace std;

// you are given a 2D matrix with sorted binary numbers in each row, find row which has maximum number of 1's
int ans = INT_MAX;
int arr[10][10];

int lowerBound(int r, int c) {
  int l = 0, h = c - 1;
  while (l <= h) {
    int mid = (l + h) / 2;

    if (arr[r][mid] == 1) {
      if (arr[r][mid] == arr[r][mid - 1])
        h = mid - 1;
      else return mid;
    } else if (arr[r][mid] < 1) {
      l = mid + 1;
    }
  }
  return INT_MAX;
}

int main() {
  int n, m;
  cin >> n >> m;


  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  int row = INT_MAX;

  for (int i = 0; i < n; i++) {
    int idx = lowerBound(i, m);
    if (idx < ans) {
      ans = idx;
      row = i;
    }
  }

  cout << "ans = > " << row;

  return 0;
}