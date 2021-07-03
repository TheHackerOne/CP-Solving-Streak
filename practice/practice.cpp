// #include<bits/stdc++.h>
// using namespace std;

// // Euler's Totient says that
// // theta(n) gives number of "m"(co-primes) such that 1 <= m < n and gcd(n, m) = 1
// // PROPERTY
// // theta(a*b) = theta(a) * theta(b), iff gcd(a, b) = 1
// // N = p1^a * p2^b * ..... * pn^k
// // theta(N) = theta(p1^a * p2^b * ..... * pn^k) = theta(p1^a) * theta(p2^b) * ... * theta(pn^k) --------- 1
// // theta(p1^a) = p1^a(total elements) - p1^(a-1)(elements which are not co-prime to p1^a)
// // theta(p1^a) = p1^a - p1^(a-1) = (p1^a)*(1 - 1/a) --------------- 2
// // using 2 in 1, we get
// // EULER TOTIENT FINAL FORMULA
// // theta(N) = N * (1 - 1/p1) * (1 - 1/p2) * ...... * (1 - 1/pk)


// void eulerTotient(int n){
//   int phi[n+1];
//   for(int i=1;i<=n;i++)
//     phi[i] = i;

//   for(int i=2;i<=n;i++){
//     if(phi[i] == i){
//       phi[i] = i - 1;
//       for(int j=2*i;j<=n;j+=i){
//         phi[j] = (phi[j]*(i-1))/i;
//       }
//     }
//   }
// }

// int main() {
//   int n;
//   cin>>n;

//   eulerTotient(n);

//   return 0;
// }


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