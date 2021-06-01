#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
	void printGraph(vector<int> adjList[], int V) {
		for (int i = 0; i < V; i++) {
			cout << i << " : ";
			for (int j : adjList[i])
				cout << j << " ";
			cout << endl;
		}
	}

	void bfs(vector<int> adjList[], int src, int V) {
		queue<int> q;
		int visited[V] = {0};
		q.push(src);
		visited[src] = 1;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			cout << curr << " ";
			for (int child : adjList[curr]) {
				if (!visited[child]) {
					visited[child] = 1;
					q.push(child);
				}
			}
		}
	}
};

int main() {
	int V, E;
	cin >> V >> E;
	vector<int> adjList[V];
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	Solution obj;
	obj.printGraph(adjList, V);
	obj.bfs(adjList, 0, V);

	return 0;
}