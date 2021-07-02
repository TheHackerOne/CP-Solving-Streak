#include<bits/stdc++.h>
using namespace std;

// Divisors of Factorial
// No. of divisors of ( n! )
// We know that for any number N, we have
// N = p1^a * p2^b * ... * pn^k
// No. of Divisors = (a+1) * (b+1) * ... * (k+1)

#define MOD 1000000007
#define ll long long
#define pb push_back

int prime[100009];
vector<int> primes;

void sieve() {
  for (int i = 0; i <= 1e5 + 9 - 1; i++)
    prime[i] = 1;
  prime[0] = prime[1] = 1;

  for (int i = 2; i * i < 1e5 + 9; i++) {
    if (prime[i]) {
      for (int j = i * i; j < 1e5 + 9; j += i)
        prime[j] = 0;
    }
  }

  for (int i = 0; i < 1e5 + 9; i++)
    if (prime[i])
      primes.pb(i);
}

int divisors(int n) {
  ll divisorCount = 1;
  for (int i = 2; primes[i] <= n; i++) {
    ll count = 0;
    int k = i;
    while (n / k != 0) {
      count = (count + n / k) % MOD;
      k *= k;
    }
    divisorCount = ((divisorCount % MOD) * ((count + 1) % MOD)) % MOD;
  }
  return divisorCount;
}

int main() {
  sieve();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << divisors(n) << endl;
  }


  return 0;
}