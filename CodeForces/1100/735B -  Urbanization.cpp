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
// COMPLEX CLASS
#define X real()
#define Y imag()
#define dist(a, b) abs(a-b)
#define angle(x) ((arg(x) * 180) / PI)
#define pos(p, x, y) (conj(p - x) * (p - y)).Y
// pos > 0 = left, pos < 0 = right, pos = 0 = on the vector


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef complex<lld> C;

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
	int n, n1, n2;
	cin >> n >> n1 >> n2;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(all(a));
	int mini = n1, maxi = n2;
	if (n1 != n2) {
		mini = n1 < n2 ? n1 : n2;
		maxi = n1 > n2 ? n1 : n2;
	}
	double ans1 = 0;
	debug(a)
	for (int i = 0; i < mini; i++) {
		ans1 += a[n - 1 - i];
		a.pop_back();
	}
	debug(a)
	ans1 = ans1 / (double)mini;
	double ans2 = 0;
	int size = a.size();
	for (int i = 0; i < maxi; i++) {
		ans2 += a[size - 1 - i];
		a.pop_back();
	}
	ans2 = ans2 / (double)maxi;
	debug(ans1)
	debug(ans2)
	cout << setprecision(8);
	cout << fixed;
	cout << ans1 + ans2 << nline;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	fastio();
	solve();

	return 0;
}