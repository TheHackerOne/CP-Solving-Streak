#include<bits/stdc++.h>
using namespace std;

pair<int, int> findPositions(vector<int> &a, int x) {
	int first = 0, last = a.size() - 1;
	int lowerBound = INT_MAX, upperBound = INT_MAX;
	while (first <= last) {
		int mid = (first + last) / 2;
		if (a[mid] == x) {
			if (a[mid - 1] == x) last = mid - 1;
			else {
				lowerBound = mid;
				break;
			}
		} else if (a[mid] > x) {
			last = mid - 1;
		} else {
			first = mid + 1;
		}
	}
	first = 0, last = a.size() - 1;
	while (first <= last) {
		int mid = (first + last) / 2;
		if (a[mid] == x) {
			if (a[mid + 1] == x) first = mid + 1;
			else {
				upperBound = mid;
				break;
			}
		} else if (a[mid] > x) {
			last = mid - 1;
		} else {
			first = mid + 1;
		}
	}
	if (lowerBound == INT_MAX) return { -1, -1};
	else return {lowerBound, upperBound};
}

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	pair<int, int> p = findPositions(a, x);
	cout << p.first << " " << p.second << endl;

	return 0;
}