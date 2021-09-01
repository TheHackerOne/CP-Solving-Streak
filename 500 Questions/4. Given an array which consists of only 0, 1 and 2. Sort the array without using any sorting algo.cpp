#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	int zeros = 0, ones = 0, twos = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) zeros++;
		else if (a[i] == 1) ones++;
		else twos++;
	}
	int i = 0;
	while (zeros--) {
		a[i] = 0;
		i++;
	}
	while (ones--) {
		a[i] = 1;
		i++;
	}
	while (twos--) {
		a[i] = 2;
		i++;
	}

	for (int i = 0; i < n; i++) cout << a[i] << " ";

	return 0;
}