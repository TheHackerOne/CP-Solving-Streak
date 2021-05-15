#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int visited[N];
int visited1[N];
vector<int> a[N];

void DFS(int src) {
	cout << src << " ";
	visited[src] = 1;
	for (int i : a[src]) {
		if (visited[i] == 0)
			DFS(i);
	}
}

void print(int src) {
	cout << src << " : ";
	visited1[src] = 1;
	for (int i : a[src])
		cout << i << " ";
	cout << endl;
	for (int i : a[src])
		if (visited1[i] == 0)
			print(i);
}

int main() {
	int nodes, edges;
	cin >> nodes >> edges;
	for (int i = 0; i < edges; i++) {
		int n, m;
		cin >> n >> m;
		a[n].push_back(m);
		a[m].push_back(n);
	}

	DFS(1);
	cout << endl;
	print(1);

	return 0;
}