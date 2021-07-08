#include<bits/stdc++.h>
using namespace std;

// Matrix Exponentiation (for Fibonacci series)
// Matrix M * kth state = (k + 1)th state
// M^(k-1) * [initial state] = kth state variables
// kth state matrix / initial matrix has all unknown variables
// M is the matrix we have to find

void multiply(int A[2][2], int M[2][2]) {
  int firstVal = A[0][0] * M[0][0] + A[0][1] * M[1][0];
  int secondVal = A[0][0] * M[0][1] + A[0][1] * M[1][1];
  int thirdVal = A[1][0] * M[0][0] + A[1][1] * M[1][0];
  int fourthVal = A[1][0] * M[0][1] + A[1][1] * M[1][1];
  A[0][0] = firstVal;
  A[0][1] = secondVal;
  A[1][0] = thirdVal;
  A[1][1] = fourthVal;
}

void power(int A[2][2], int n) {
  if (n == 0 || n == 1) {
    return;
  }

  power(A, n / 2);

  multiply(A, A);
  if ((n % 2) != 0) {
    int M[2][2] = {{1, 1}, {1, 0}};
    multiply(A, M);
  }
}

int fib(int n) {
  int A[2][2] = {{1, 1}, {1, 0}};

  if (n == 0) return 0;

  power(A, n - 1);
  return A[0][0];
}

int main() {
  int n;
  cin >> n;
  cout << fib(n) << endl;

  return 0;
}