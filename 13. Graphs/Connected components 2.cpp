#include<bits/stdc++.h>
using namespace std;

vector<int> vis(100, 0);

void dfs(int src, vector<int> gra[]) {
	vis[src] = 1;
	for (auto &i : gra[src]) {
		if (!vis[i]) {
			dfs(i, gra);
		}
	}
}

vector<int> vis2(100, 0);
void bfs(int src, vector<int> gra[]) {
	queue<pair<int, int>> q;
	q.push({src, 1});
	map<int, vector<int>> mp;
	mp[1].push_back(src);
	vis2[src] = 1;
	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();
		int node = curr.first;
		int lvl = curr.second;
		for (int &i : gra[node]) {
			if (!vis2[i]) {
				q.push({i, lvl + 1});
				vis2[i] = 1;
				mp[lvl + 1].push_back(i);
			}
		}
	}
}


int main() {
	int edge, nodes;
	cin >> edge >> nodes;
	vector<int> gra[nodes];
	for (int i = 0; i < edge; i++) {
		int a, b;
		cin >> a >> b;
		gra[a].push_back(b);
		gra[b].push_back(a);
	}

	int connectedComp = 0;
	for (int i = 0; i < nodes; i++) {
		if (!vis[i]) {
			dfs(i, gra);
			connectedComp++;
		}
	}
	cout << "Connected Components using DFS  -> " << connectedComp << endl;

	int connectedComp1 = 0;
	for (int i = 0; i < nodes; i++) {
		if (!vis2[i]) {
			bfs(i, gra);
			connectedComp1++;
		}
	}
	cout << "Connected Components using BFS -> " << connectedComp1 << endl;

	return 0;
}