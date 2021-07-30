#include<bits/stdc++.h>
using namespace std;

// Euler's Totient says that
// theta(n) gives number of "m"(co-primes) such that 1 <= m < n and gcd(n, m) = 1
// PROPERTY
// theta(a*b) = theta(a) * theta(b), iff gcd(a, b) = 1
// N = p1^a * p2^b * ..... * pn^k
// theta(N) = theta(p1^a * p2^b * ..... * pn^k) = theta(p1^a) * theta(p2^b) * ... * theta(pn^k) --------- 1
// theta(p1^a) = p1^a(total elements) - p1^(a-1)(elements which are not co-prime to p1^a)
// theta(p1^a) = p1^a - p1^(a-1) = (p1^a)*(1 - 1/a) --------------- 2
// using 2 in 1, we get
// EULER TOTIENT FINAL FORMULA
// theta(N) = N * (1 - 1/p1) * (1 - 1/p2) * ...... * (1 - 1/pk)

int eulerTotientBasic(int n) {
  int result = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0)
        n /= i;
      result = result - result / i;
    }
  }
  if (n > 1)
    result = result - result / n;
  return result;
}

void eulerTotient(int n) {
  int phi[n + 1];
  for (int i = 1; i <= n; i++)
    phi[i] = i;

  for (int i = 2; i <= n; i++) {
    if (phi[i] == i) {
      phi[i] = i - 1;
      for (int j = 2 * i; j <= n; j += i) {
        phi[j] = (phi[j] * (i - 1)) / i;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << "Euler Totient for " << i << " is " << phi[i] << endl;
  }
}

int main() {
  int n;
  cin >> n;

  eulerTotient(n);

  return 0;
}


