
#include<bits/stdc++.h>
using namespace std;
// Function to find minimum swaps to sort an array
int minSwaps(vector<int> &v) {
	vector<int> sorted = v;
	sort(sorted.begin(), sorted.end());
	unordered_map<int, int> mp;
	for (int i = 0; i < v.size(); i++) {
		mp[sorted[i]] = i;
	}
	int swaps = 0;
	for (int i = 0; i < v.size(); i++) {
		int correct_position = mp[v[i]];
		if (i != correct_position) {
			swap(v[i], v[correct_position]);
			swaps++;
		}
	}
	return swaps;
}


int main()
{
	vector<int> v = { 8, 3, 14, 17, 15, 1, 12 };
	cout << minSwaps(v) << endl;
}

// This code is contributed by code_freak
