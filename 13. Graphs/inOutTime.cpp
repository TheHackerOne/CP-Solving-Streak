#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int visitedNodes[N];
int inTime[N];
int outTime[N];
vector<int> a[N];

// IN OUT time can be used to determine if one node is present
// in the subtree of other node or not(just an adjacent node)
// if inTime of one node is smaller than other node then it could be the case
// that first node is an ancestor of second node, but to confirm this we have to check that
// the outTime of first node should be greater than the second node
// inTime[1] < inTime[2] && outTime[1] > outTime[2] means 2 is present in the subtree of node 1

int timer = 1;

void inOutTime(int src) {
	visitedNodes[src] = 1;
	inTime[src] = timer++;
	for (int i : a) {
		if (!visitedNodes[i])
			inOutTime(i)
		}
	outTime = timer++;
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

	cout << inOutTime(1);
	cout << endl;
	for (int i : inTime)
		cout << i << " ";
	cout << endl;
	for (int i : outTime)
		cout << i << " ";

	return 0;
}