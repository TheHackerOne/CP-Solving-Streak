#include<bits/stdc++.h>
using namespace std;

// Time Complexity - O(log(max(a, b)))
// Brute Force Time Complexity - O(min(a, b))

int gcd(int a, int b) {
  if (b == 0)
    return a;
  gcd(b, a % b);
}

int main() {
  int a, b;
  cin >> a >> b;

  cout << "GCD -> " << gcd(a, b);

  return 0;
}