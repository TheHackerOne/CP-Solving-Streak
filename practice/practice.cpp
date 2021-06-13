
#include <bits/stdc++.h>

using namespace std;

long long traverseDeep(long long node, vector<vector<long long>> & G, long long n) {
  vector<bool> done(n + 1, false);
  long long fd = -1, far;
  done[node] = true;
  queue<pair<long long, long long>> qu; qu.push({node, 0});
  while (qu.size()) {
    auto pi = qu.front(); qu.pop();
    long long nod = pi.first, dis = pi.second;
    if (fd < dis) fd = dis, far = nod;
    for (auto chdNonu : G[nod]) {
      if (done[chdNonu]) continue;
      done[chdNonu] = true;
      qu.push({chdNonu, dis + 1});
    }
  }
  return far;
}

void dfs(long long nod, long long par, vector<vector<long long>> & G, vector<long long> & H, vector<long long> & li, long long cur) {
  bool isleaf = true;
  long long mx = 0;
  for (auto chdNonu : G[nod])
    if (chdNonu != par)
      isleaf = false, mx = max(mx, H[chdNonu]);
  if (isleaf) {
    li.push_back(cur);
    return;
  }

  long long c = 0;
  for (auto chdNonu : G[nod]) {
    if (chdNonu == par) continue;
    if (H[chdNonu] == mx && c == 0) {
      dfs(chdNonu, nod, G, H, li, cur + 1); c++;
    }
    else dfs(chdNonu, nod, G, H, li, 1);
  }
}

void fixHeight(long long nod, long long par, vector<vector<long long>> & G, vector<long long> & H) {
  bool isleaf = true;
  for (auto chdNonu : G[nod]) {
    if (chdNonu == par) continue;
    isleaf = false;
    fixHeight(chdNonu, nod, G, H);
    H[nod] = max(H[nod], 1 + H[chdNonu]);
  }
  if (isleaf) H[nod] = 1;
}

void longoLines(long long nod, long long par, vector<vector<long long>> & G, vector<long long>&li, long long n) {
  vector<long long> H(n + 1, 0);
  fixHeight(nod, par, G, H);
  dfs(nod, par, G, H, li, 1);
}

long long getSol(vector<vector<long long>> & gr, long long n, long long k) {
  if (k == 1) return 1;
  long long u = traverseDeep(1, gr, n);
  vector<long long> li;
  longoLines(u, 0, gr, li, n);
  sort(li.rbegin(), li.rend());
  long long size = 1, total = 0, i = 0;
  while (total < k)
    size++; total += li[i++];

  return size;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    long long u, v;

    cin >> n >> k;
    vector<vector<long long>> gr(n + 1);
    for (long long i = 1; i < n; i++) {
      cin >> u >> v;
      gr[u].push_back(v), gr[v].push_back(u);
    }
    cout << getSol(gr, n, k) << "\n";
  }
  return 0;
}