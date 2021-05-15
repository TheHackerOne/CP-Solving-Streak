#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int visited[N];
int visitedNodes[N];
vector<int> a[N];

void DFS(int src) {
	// cout << src << " ";
	visited[src] = 1;
	for (int i : a[src]) {
		if (visited[i] == 0)
			DFS(i);
	}
}

int numberOfConnectedComponents(int nodes) {
	int count = 0;
	for (int i = 1; i <= nodes; i++) {
		if (visited[i] == 0) {
			DFS(i);
			count++;
		}
	}
	return count;
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

	cout << numberOfConnectedComponents(nodes);
	cout << endl;

	return 0;
}