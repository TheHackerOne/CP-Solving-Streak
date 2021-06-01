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

    bool checkForCycle(vector<int> adjList[], int src, int *parent, int *visited) {
        queue<int> q;
        q.push(src);
        parent[src] = -1;
        visited[src] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int child : adjList[curr]) {
                if (!visited[child]) {
                    visited[child] = 1;
                    parent[child] = curr;
                    q.push(child);
                } else if (child != parent[curr]) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(vector<int> adjList[], int V) {
        int visited[V] = {0};
        int parent[V];
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (checkForCycle(adjList, i, parent, visited))
                    return true;
            }
        }
        return false;
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
    if (obj.isCycle(adjList, V))
        cout << "Given Graph has a cycle" << endl;
    else
        cout << "Given graph does not contain a cycle" << endl;

    return 0;
}