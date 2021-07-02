#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll GCD(ll a, ll b) {
  if (b == 0) return a;

  return GCD(b, a % b);
}

ll reduceNum(ll a, string b) {
  ll mod = 0;
  for (ll i = 0; i < b.length(); i++) {
    mod = (mod * 10 + b[i] - '0') % a;
  }
  return mod;
}

ll largeGCD(ll a, string b) {
  ll num = reduceNum(a, b);

  return GCD(a, num);
}

int main() {
  ll a;
  string b;
  cin >> a;
  cin >> b;

  cout << largeGCD(a, b) << endl;

  return 0;
}