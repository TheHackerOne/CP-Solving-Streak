
#include<bits/stdc++.h>
using namespace std;

void inorder(int a[], vector<int> &v, int n, int index) {
	if (index >= n) return;
	inorder(a, v, n, 2 * index + 1);
	v.push_back(a[index]);
	inorder(a, v, n, 2 * index + 2);
}

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
	int a[] = { 5, 6, 7, 8, 9, 10, 11 };
	int n = sizeof(a) / sizeof(a[0]);
	vector<int> v;
	inorder(a, v, n, 0);
	cout << minSwaps(v) << endl;
}

// This code is contributed by code_freak
