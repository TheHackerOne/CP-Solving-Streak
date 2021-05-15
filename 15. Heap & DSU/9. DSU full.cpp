#include<bits/stdc++.h>
using namespace std;

// 1. DSU can be used to calculate the no of connected components
// 2. DSU can be used to find MST
// 3. DSU can be used for set representation

const int N = 1e3 + 4;
int parent[N];

// path compression
int find(int a) {
	if (parent[a] < 0)
		return a;
	return parent[a] = find(parent[a]);
}

// union by rank
void unionSet(int a, int b)
{
	if (parent[a] < parent[b])
	{
		parent[a] += parent[b];
		parent[b] = a;
	}
	else
	{
		parent[b] += parent[a];
		parent[a] = b;
	}
}

int main() {
	memset(parent, -1, sizeof(parent));
	int nodes, relations;
	cin >> nodes >> relations;
	for (int i = 0; i < relations; i++) {
		int a, b;
		cin >> a >> b;
		a = find(a);
		b = find(b);
		if (a == b) continue;
		else unionSet(a, b);
	}

	return 0;
}