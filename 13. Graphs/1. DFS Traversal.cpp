#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
	void dfsHelper(vector<int> adjList[], int src, vector<int> &visited) {
		cout << src << " ";
		visited[src] = 1;
		for (int child : adjList[src]) {
			if (!visited[child])
				dfsHelper(adjList, child, visited);
		}
	}

public:
	void printGraph(vector<int> adjList[], int V) {
		for (int i = 0; i < V; i++) {
			cout << i << " : ";
			for (int j : adjList[i])
				cout << j << " ";
			cout << endl;
		}
	}

	void dfs(vector<int> adjList[], int V) {
		vector<int> visited(V, 0);
		dfsHelper(adjList, 0, visited);
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
	obj.dfs(adjList, V );

	return 0;
}