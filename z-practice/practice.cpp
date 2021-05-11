#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int prime[N];

void primeNumbers(int n) {
	prime[1] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n / i; j++) {
			int x = i * j;
			prime[x] = 0;
		}
	}
}

int main() {
	int n;
	cin >> n;
	memset(prime, -1, sizeof(prime));

	primeNumbers(n);

	for (int i = 1; i <= n; i++) {
		if (prime[i] == -1)
			cout << i << ", ";
	}

	return 0;
}