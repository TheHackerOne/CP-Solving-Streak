#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
// int visited[N];
int visitedNodes[N];
int parent[N];
vector<int> a[N];


bool cycleDetection(int src) {
	visitedNodes[src] = 1;
	for (int i : a[src]) {
		if (!visitedNodes[i]) {
			parent[i] = src;
			if (cycleDetection(i))
				return true;
		} else {
			if (i != parent[src])
				return true;
		}
	}
	return false;
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

	cout << cycleDetection(1);
	cout << endl;

	return 0;
}