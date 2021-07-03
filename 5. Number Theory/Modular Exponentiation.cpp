#include<bits/stdc++.h>
using namespace std;

// Modular Exponentiation
// (a^b % c)

int modeExpo(int a, int b, int c) {
  if (a == 0) return 0;
  if (b == 0) return 1;

  long ans;
  if (b % 2 == 0) {
    long smallAns = modeExpo(a, b / 2, c);
    ans = (smallAns * smallAns) % c;
  } else {
    long smallAns = modeExpo(a, b - 1, c);
    ans = a % c;
    ans = (ans * smallAns) % c;
  }
  return int((ans + c) % c); // for Negative Numbers
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << modeExpo(a, b, c);

  return 0;
}