#include<bits/stdc++.h>
using namespace std;
// Prime Factors of a Number

void primeFactorization(int n) {
  int num = n;
  for (int i = 2; i * i <= n; i++) {
    while (num % i == 0) {
      num /= i;
      cout << i << " ";
    }
  }
  if (num != 1) {
    cout << num << endl;
  }
}

int main() {
  int n;
  cin >> n;

  primeFactorization(n);

  return 0;
}