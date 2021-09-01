#include<bits/stdc++.h>
using namespace std;

void print(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

vector<int>  unionArray, intersectionArray;
void doUnion(int a[], int n, int b[], int m)  {
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] < b[j]) {
			unionArray.push_back(a[i++]);
		} else if (a[i] > b[j]) {
			unionArray.push_back(b[j++]);
		} else {
			unionArray.push_back(a[i]);
			intersectionArray.push_back(a[i]);
			i++;
			j++;
		}
	}
	while (i < n) {
		unionArray.push_back(a[i++]);
	}
	while (j < m) {
		unionArray.push_back(b[j++]);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	doUnion(a, n, b, m);
	for (int i = 0; i < unionArray.size(); i++) {
		cout << unionArray[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < intersectionArray.size(); i++) {
		cout << intersectionArray[i] << " ";
	}

	return 0;
}