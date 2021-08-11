#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

// using namespace __gnu_pbds;
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


long long mod(long long x) { return ((x % MOD + MOD) % MOD); }
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }

void solve() {
	int n, m;
	cin >> n >> m;
	int arr[n + 2][m + 2], visited[n + 2][m + 2];
	memset(arr, 0, sizeof(arr));
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 0) {
				if ((i == 1 || j == 1 || i == n || j == m) && (visited[i][j - 1] == 0 && visited[i][j + 1] == 0 && visited[i - 1][j] == 0 && visited[i + 1][j] == 0 && visited[i + 1][j + 1] == 0 && visited[i - 1][j - 1] == 0 && visited[i - 1][j + 1] == 0 && visited[i + 1][j - 1] == 0) ) {
					// visited[i][j - 1] = visited[i][j + 1] = visited[i - 1][j] = visited[i + 1][j] = visited[i + 1][j + 1] = visited[i - 1][j - 1] = visited[i - 1][j + 1] = visited[i + 1][j - 1] = 1;
					arr[i][j] = 1;
					visited[i][j] = 1;
				}
			} else continue;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << arr[i][j];
		}
		cout << nline;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	fastio();
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}