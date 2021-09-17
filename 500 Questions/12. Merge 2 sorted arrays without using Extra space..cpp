#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m) {
	// code here
	int gap = ceil((n + m) / (float)2);
	while (gap >= 1) {
		int first = 0, second = first + gap;
		while (second < n + m) {
			if (second < n && (arr1[first] > arr1[second])) {
				swap(arr1[first], arr1[second]);
			} else if (first < n && second >= n && (arr1[first] > arr2[second - n])) {
				swap(arr1[first], arr2[second - n]);
			} else if (first >= n && (arr2[first - n] > arr2[second - n])) {
				swap(arr2[first - n], arr2[second - n]);
			}
			first++;
			second++;
		}
		if (gap == 1) break;
		gap = ceil(gap / (float)2);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	int arr1[n], arr2[m];
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	merge(arr1, arr2, n, m);

	for (int i = 0; i < n; i++) cout << arr1[i] << " ";
	cout << endl;
	for (int j = 0; j < m; j++) cout << arr2[j] << " ";
	cout << endl;

	return 0;
}