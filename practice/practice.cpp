#include<bits/stdc++.h>
using namespace std;

int *color;

bool isBipartite(int src, int col , vector<int> adjList[]) {
    queue<int> q;
    color[src] = col;
    q.push(src);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        int col = color[curr];
        for (int child : adjList[curr]) {
            if (color[child] == -1) {
                color[child] = !col;
                q.push(child);
            } else if (color[child] == color[curr]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    color = new int[n + 1];
    for (int i = 1; i <= n; i++)
        color[i] = -1;

    vector<int> adjList[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    if (isBipartite(1, 0, adjList))
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is not Bipartite" << endl;


    return 0;
}