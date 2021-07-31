#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool isValid(string s) {
	bool a_flag = false;
	int a_index;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a')
			a_index = i , a_flag = true;
	}
	if (!a_flag) return false;
	else {
		int L = a_index, R = a_index;
		char currChar = 'a';
		while (L - 1 >= 0 || R + 1 < s.length()) {
			currChar += 1;
			if (s[L - 1] == currChar) {
				L -= 1;
			} else if (s[R + 1] == currChar) {
				R += 1;
			} else {
				return false;
			}
		}
	}

	return true;
}

int main() {
	ll t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		if (isValid(s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}