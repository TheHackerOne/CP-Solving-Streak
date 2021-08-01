#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;

	map<char, int> mp;
	char ch = 'a';
	for (int i = 0; i < 26; i++)
		mp[ch + i] = i + 1;
	int prefixSum[s.length() + 1];
	prefixSum[1] = mp[s[0]];
	prefixSum[0] = 0;
	for (int i = 2; i <= s.length(); i++) {
		prefixSum[i] = 0;
		prefixSum[i] = prefixSum[i - 1] + mp[s[i - 1]];
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << prefixSum[r] - prefixSum[l - 1] << endl;
	}

	return 0;
}