#include<bits/stdc++.h>
using namespace std;

void print(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mid = 0, forw = 0;
	while (forw < n) {
		if (a[forw] < 0) {
			swap(a[mid++], a[forw++]);
		} else forw++;
	}

	print(a, n);

	return 0;
}