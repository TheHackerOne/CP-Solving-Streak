#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int visitedNodes[N];
vector<int> a[N];

void BFS(int src) {
	queue<int> q;
	q.push(src);
	visitedNodes[src] = 1;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << " : " ;
		for (int i : a[front]) {
			if (!visitedNodes[i]) {
				visitedNodes[i] = 1;
				q.push(i);
				cout << i << " ";
			}
		}
		cout << endl;
	}
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
	BFS(1);


	return 0;
}