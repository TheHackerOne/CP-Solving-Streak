#include<bits/stdc++.h>
using namespace std;

int *visited;
int *parent;


bool isCycle(int src, vector<int> adjList[]) {
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    parent[src] = -1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int child : adjList[curr]) {
            if (!visited[child]) {
                parent[child] = curr;
                visited[child] = 1;
                q.push(child);
            } else if (child != parent[curr]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    visited = new int[n + 1];
    parent = new int[n + 1];
    for (int i = 1; i <= n; i++)
        visited[i] = 0, parent[i] = 0;

    vector<int> adjList[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    if (isCycle(1, adjList))
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph does not contain a cycle" << endl;


    return 0;
}