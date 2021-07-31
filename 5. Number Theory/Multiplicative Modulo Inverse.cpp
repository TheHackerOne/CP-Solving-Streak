#include<bits/stdc++.h>
using namespace std;

// Multiplicative Inverse
// (A * B) = 1, then B = 1 / A
// Multiplicative modulo Inverse
// (A * B) % m = 1
// (A * B - 1) % m = 0 [ (A*B-1) is a multiple of m ]
// (A * B - 1) = mq
// (A * B - 1) - m*q = 0
// A*B - m*q = 1
// A*B + m*(-q) = 1
// Above equation is similar to Ax + By = gcd(A, B)


class Triplet {
public:
  int x;
  int y;
  int gcd;
};

Triplet extendedEuclid(int a, int b) {
  if (b == 0) {
    Triplet ans;
    ans.gcd = a;
    ans.x = 1;
    ans.y = 0;
    return ans;
  }

  Triplet smallAns = extendedEuclid(b, a % b);
  Triplet ans;
  ans.gcd = smallAns.gcd;
  ans.x = smallAns.y;
  ans.y = smallAns.x - (a / b) * smallAns.y;
  return ans;
}

int multiplicativeModuloInverse(int a, int m) {
  return extendedEuclid(a, m).x;
}

int main() {
  int a, m;
  cin >> a >> m;

  int ans = multiplicativeModuloInverse(a, m);
  cout << ans << endl;

  return 0;
}













