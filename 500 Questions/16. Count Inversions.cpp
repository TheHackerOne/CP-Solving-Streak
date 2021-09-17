#include<bits/stdc++.h>
using namespace std;

long long int counter;

void mergeSort(long long int a[], long long int l, long long int h) {
	long long int mid = (l + h) / 2;
	long long int ele = h - l + 1;
	long long int temp[ele];
	long long int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= h) {
		if (a[i] < a[j]) temp[k++] = a[i++];
		else if (a[i] == a[j]) temp[k++] = a[i++];
		else if (a[i] > a[j]) {
			temp[k++] = a[j++];
			counter += (mid - i + 1);
		}
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= h) {
		temp[k++] = a[j++];
	}
	int idx = 0;
	for (int i = l; i <= h; i++) {
		a[i] = temp[idx];
		idx++;
	}
}

void merge(long long int a[], long long int l, long long int h) {
	if (l >= h) return;
	long long int mid = (l + h) / 2;
	merge(a, l, mid);
	merge(a, mid + 1, h);
	mergeSort(a, l, h);
}

long long int inversionCount(long long arr[], long long N)
{
	counter = 0;
	merge(arr, 0, N - 1);
	return counter;
}

int main() {
	int n;
	cin >> n;
	long long int  a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << inversionCount(a, n);

	return 0;
}