#include<bits/stdc++.h>

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
#define nline "\n"
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


long long mod(long long x) { return ((x % MOD + MOD) % MOD); }
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }

bool comp(ll a, ll b) {
	return  a > b;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];
		ll count = 0;
		vector<int> even;
		for (int i = 0; i < n; i++) {
			if (arr[i] % 2 == 0)
				even.push_back(arr[i]);
		}
		for (int i = 0; i < n; i++) {
			if (arr[i] % 2 != 0)
				even.push_back(arr[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (__gcd(even[i], (2 * even[j])) == 1)
					count++;
			}
		}
		ll total = (n * (n - 1)) / 2;
		debug(total)
		debug(count)
		cout << total - count << nline;
	}

	return 0;
}