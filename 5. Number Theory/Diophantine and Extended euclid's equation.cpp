#include<bits/stdc++.h>
using namespace std;

// Diophantine Equations
// Linear Dio Equations
// ax + by = c
// Solution x, y for the above equations are integeral only when GCD(a, b) divides c

// Extended Euclid's equation says that if ax + by = gcd(a, b), find value of x and y
// and from Dio equations we know that the solution of the equation will exist and those solutions will be integers

// ax + by = gcd(a, b) ------- 1
// gcd(a, b) = gcd(b, a % b)
// bx1 + (a % b)y1 = gcd(b, a % b) ------- 2
// Comparing 1 and 2, we get
// x = y1
// y = x1 - (a/b) * y1


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

int main() {
  int a, b;
  cin >> a >> b;

  Triplet ans = extendedEuclid(a, b);

  cout << "GCD = " << ans.gcd << endl;
  cout << "X = " << ans.x << endl;
  cout << "Y = " << ans.y << endl;

  return 0;
}













