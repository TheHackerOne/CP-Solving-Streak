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
	ll n;
	cin >> n;
	vector<ll> a(n + 2);
	for (ll i = 1; i <= n; i++) cin >> a[i];
	a[0] = 0, a[n + 1] = 0;
	vector<ll> verti;
	ll totalHeight = 0;
	for (ll i = 1; i <= n + 1; i++) {
		ll x = abs(a[i] - a[i - 1]);
		verti.pb(x);
		totalHeight += x;
	}
	debug(verti)

	ll peaks = 0;
	vector<ll> peakDiff;
	ll totalPeak = 0;
	for (ll i = 1; i <= n; i++) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			peaks++;
			ll minrem = max(a[i - 1], a[i + 1]);
			peakDiff.pb(a[i] - minrem);
			totalPeak += a[i] - minrem;
		}
	}
	debug(totalHeight)
	debug(peakDiff)

	cout << (totalHeight - 2 * totalPeak) + totalPeak << nline;
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