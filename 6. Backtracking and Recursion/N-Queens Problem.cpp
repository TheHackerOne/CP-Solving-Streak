#include<bits/stdc++.h>
using namespace std;

int board[11][11];

bool isValid(int r, int c, int n) {
  for (int i = r - 1; i >= 0; i--) {
    if (board[i][c]) return false;
  }

  for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j]) return false;
  }

  for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
    if (board[i][j]) return false;
  }

  return true;
}

void nQueensHelper(int n, int row) {
  if (row == n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << board[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    return;
  }

  for (int i = 0; i < n; i++) {
    if (isValid(row, i, n)) {
      board[row][i] = 1;
      nQueensHelper(n, row + 1);
      board[row][i] = 0;
    }
  }
}

void nQueens(int n) {
  memset(board, 0, 11 * 11 * sizeof(int));

  nQueensHelper(n, 0);
}

int main() {
  int n;
  cin >> n;

  nQueens(n);

  return 0;
}