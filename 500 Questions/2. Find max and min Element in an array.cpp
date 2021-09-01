#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int maxi = INT_MIN, mini = INT_MAX;
	for (int i = 0; i < n; i++) {
		maxi = max(maxi, a[i]);
		mini = min(mini, a[i]);
	}
	cout << "Max = " << maxi << endl;
	cout << "Min = " << mini << endl;

	return 0;
}