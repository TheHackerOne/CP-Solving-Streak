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
#define X real()
#define Y imag()
#define dist(a, b) abs(a-b)
#define angle(x) ((arg(x) * 180) / PI)


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
	C a = {3, -1};
	C b = {2, 6};
	C sum = a + b;
	C x = {0, 99};
	cout << sum.X << " " << sum.Y << nline;
	cout << dist(a, b) << nline;
	cout << angle(x) << nline;
	C f = {0, 0};
	C s = {2, 2};
	C p1 = {0, 2};
	C p2 = {2, 0};
	C p3 = {3, 3};
	// cross product APPLICATION 1 : to TEST points location with respect to a line
	C cp = conj(p1 - f) * (p1 - s);
	cout << cp.X << " " << cp.Y << nline;
	if ((conj(p1 - f) * (p1 - s)).Y > 0) {
		cout << "left me haiiiii" << nline;
	} else cout << "right me haiiii" << nline;


	C cp1 = conj(p2 - f) * (p2 - s); // cross product
	cout << cp1.X << " " << cp1.Y << nline;
	if ((conj(p2 - f) * (p2 - s)).Y > 0) {
		cout << "left me haiiiii" << nline;
	} else cout << "right me haiiii" << nline;


	C cp2 = conj(p3 - f) * (p3 - s); // cross product
	cout << cp2.X << " " << cp2.Y << nline;
	if ((conj(p3 - f) * (p3 - s)).Y > 0) {
		cout << "left me haiiiii" << nline;
	} else if ((conj(p3 - f) * (p3 - s)).Y == 0) {
		cout << "line pe haiii" << nline;
	} else cout << "right me haiiii" << nline;

	// APPLICATION 2: shortest distance of a point from a line
	// d = ((s1-p)X(s2-p)/|s2 - s1|)
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