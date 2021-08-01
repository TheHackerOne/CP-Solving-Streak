#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> arr(2 * n);
		int oddCount = 0;
		int evenCount = 0;

		for (int i = 0; i < 2 * n; i++) {
			cin >> arr[i];
			if (arr[i] % 2 == 0) evenCount++;
			else oddCount++;
		}

		if (oddCount == evenCount) cout << "YES" << endl;
		else cout << "NO" << endl;

	}

	return 0;
}