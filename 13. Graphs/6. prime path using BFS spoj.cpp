#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 4;
vector<int> primes;
int dist[N];
int visited[N];
vector<int> adjList[N];

bool prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

void AllPrimes() {
	for (int i = 1000; i <= 9999; i++) {
		if (prime(i))
			primes.push_back(i);;
	}
}

bool isValid(int a, int b) {
	int count = 0;
	while (a > 0) {
		if ((a % 10) != (b % 10)) count++;
		a /= 10, b /= 10;
	}
	if (count == 1) return true;
	else return false;
}

void CreateGraph(int a, int b) {
	for (int i = 0; i < primes.size(); i++) {
		int prime1 = primes[i];
		for (int j = i + 1; j < primes.size(); j++) {
			int prime2 = primes[j];
			if (isValid(prime1, prime2)) {
				adjList[prime1].push_back(prime2);
				adjList[prime2].push_back(prime1);
			}
		}
	}
}

void BFS(int src) {
	queue<int> q;
	q.push(src);
	visited[src] = 1;
	dist[src] = 0;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i : adjList[front]) {
			if (!visited[i]) {
				visited[i] = 1;
				q.push(i);
				dist[i] = dist[front] + 1;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	AllPrimes();
	while (t--) {
		int a, b;
		cin >> a >> b;
		memset(dist, -1, sizeof(dist));
		memset(visited, 0, sizeof(visited));

		CreateGraph(a, b);

		BFS(a);
		if (dist[b] == -1) cout << "Impossible" << endl;
		else cout << dist[b] << endl;
	}

	return 0;
}

// 3
// 1033 8179
// 1373 8017
// 1033 1033

// 6
// 7
// 0
