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
	int a, b, c, r;
	cin >> a >> b >> c >> r;
	if (a > b) swap(a, b);
	vector<int> arr;
	arr.pb(a);
	arr.pb(b);
	arr.pb(c);
	// arr.pb(r);
	int minEle = *min_element(all(arr));
	int dia = 2 * r;
	if (a < 0 || b < 0 || c < 0) {
		arr[0] += abs(minEle);
		arr[1] += abs(minEle);
		arr[2] += abs(minEle);
	}
	int circleL = arr[2] - r, circleR = arr[2] + r;
	int totalDist = abs(arr[1] - arr[0]);
	debug(c)
	debug(arr)
	debug(circleL)
	debug(circleR)
	if (circleL < arr[0] && circleR > arr[1]) {
		cout << 0 << nline;
		debug(0);
	} else if (circleL >= arr[1] || circleR <= arr[0]) {
		cout << totalDist << nline;
		debug(totalDist)
	} else if (circleL >= arr[0] && circleR <= arr[1]) {
		cout << totalDist - (2 * r) << nline;
		debug( totalDist - (2 * r))
	} else if (abs(arr[2] - arr[0]) < r) {
		int inc = arr[2] + r - arr[0];
		cout << totalDist - inc << nline;
		debug(totalDist - inc)
	} else if (abs(arr[2] - arr[1]) < r) {
		int inc = arr[1] - (arr[2] - r);
		cout << totalDist - inc << nline;
		debug(totalDist - inc)
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