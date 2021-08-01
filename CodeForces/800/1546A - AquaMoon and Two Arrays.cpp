#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr1[n + 1], arr2[n + 1], sum1 = 0, sum2 = 0;

		for (int i = 0; i < n; i++) cin >> arr1[i + 1], sum1 += arr1[i + 1];
		for (int i = 0; i < n; i++) cin >> arr2[i + 1], sum2 += arr2[i + 1];

		if (sum1 != sum2 ) {
			cout << "-1" << endl;
			continue;
		}

		int i = 1, j = 1;
		vector<int> icord;
		vector<int> jcord;
		while (i <= n && j <= n) {
			while (arr1[i] <= arr2[i]) {
				i++;
			}
			while (arr1[j] >= arr2[j]) {
				j++;
			}
			if (i > n || j > n) break;
			while ((arr1[i] != arr2[i]) && (arr1[j] != arr2[j])) {
				icord.push_back(i);
				jcord.push_back(j);
				arr1[i]--;
				arr1[j]++;
			}
			if (arr1[i] == arr2[i]) i++;
			if (arr1[j] == arr2[j]) j++;
		}

		cout << icord.size() << endl;

		for (int i = 0; i < icord.size(); i++) {
			cout << icord[i] << " " << jcord[i] << endl;
		}

	}

	return 0;
}