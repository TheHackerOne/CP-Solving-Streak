#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		int res = n - 1, count = 1;
		int bari = sqrt(n);
		int prevNum = 3;
		for (int i = 0; i < bari - 1; i++) {
			res -= prevNum;
			prevNum += 2;
			count++;
		}
		if (res == 0) cout << count << endl;
		else cout << count + 1 << endl;
	}

	return 0;
}