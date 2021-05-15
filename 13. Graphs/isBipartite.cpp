#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
// int visited[N];
int visitedNodes[N];
int color[N];
vector<int> a[N];

// if graph has a cycle of odd length - NOT A BIPARTITE GRAPH
// if graph has a cycle of even length - A BIPARTITE GRAPH


bool isBipartite(int src, int c) {
	visitedNodes[src] = 1;
	color[src] = c;
	for (int i : a[src]) {
		if (!visitedNodes[i]) {
			if (!isBipartite(i, c ^ 1))
				return false;
		} else {
			if (color[i] == color[src])
				return false;
		}
	}
	return true;
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

	cout << isBipartite(1, 1);
	cout << endl;

	return 0;
}