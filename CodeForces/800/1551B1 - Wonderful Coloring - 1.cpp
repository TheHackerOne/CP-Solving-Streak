#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll ans = n / 3;
		if (n % 3 == 0) cout << ans << " " << ans << endl;
		else if ((ans + 2 * (ans + 1)) == n) cout << ans << " " << ans + 1 << endl;
		else cout << ans + 1 << " " << ans << endl;
	}

	return 0;
}