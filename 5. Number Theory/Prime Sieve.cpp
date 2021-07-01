#include<bits/stdc++.h>
using namespace std;

//Time Complexity - O(N log log N)
const long long int N = 1e8 + 1;
bool arr[N];

void sieve(int n) {
  for (int i = 0; i <= n; i++) arr[i] = true;
  arr[0] = arr[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (arr[i]) {
      for (int j = i * i; j <= n; j += i) {
        arr[j] = false;
      }
    }
  }
}

int main() {
  long long int n;
  cin >> n;

  sieve(n);
  for (int i = 1; i <= n; i++)
    if (arr[i])
      cout << i << endl;

  return 0;
}