#include<bits/stdc++.h>
using namespace std;

int *visited;

bool DFS(int src, int parent, vector<int> adjList[]) {
    visited[src] = 1;
    for (int child : adjList[src]) {
        if (!visited[child]) {
            if (DFS(child, src, adjList))
                return true;
        } else if (child != parent)
            return true;

    }
    return false;
}

void DFS(int src, vector<int> adjList[]) {
    visited[src] = 1;
    cout << src << " ";
    for (int child : adjList[src]) {
        if (!visited[child]) {
            DFS(child, adjList);
        }
    }
}

void BFS(int src, vector<int> adjList[]) {
    queue<int> q;
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

int main() {
    int n, m;
    cin >> n >> m;

    visited = new int[n + 1];
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    vector<int> adjList[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    BFS(1, adjList);

    // if (DFS(1, -1, adjList))
    //     cout << "Graph contains a cycle" << endl;
    // else
    //     cout << "Graph does not contain a cycle" << endl;


    return 0;
}