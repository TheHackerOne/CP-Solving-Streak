#include<bits/stdc++.h>
using namespace std;

// 1. DSU can be used to calculate the no of connected components
// 2. DSU can be used to find MST
// 3. DSU can be used for set representation

const int N = 1e3 + 4;
int parent[N];

int find(int a) {
	if (a == parent[a])
		return a;
	else return find(parent[a]);
}

void union(int a, int b) {

}

int main() {
	memset(parent, -1, sizeof(parent));
	int nodes, relations;
	cin >> nodes >> relations;
	for (int i = 0; i < relations; i++) {

	}

	return 0;
}