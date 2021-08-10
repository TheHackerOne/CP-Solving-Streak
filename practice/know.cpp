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

bool comp(int a, int b) {
	return a < b;
}

void solve() {
	cout << "comparator" << nline;
	vector<int> arr = {1, 6, 3, 2, 7, 9, 6, 34, 2};
	sort(arr.begin(), arr.end(), comp);
	for (int i : arr) cout << i << " ";

	cout << nline << nline;

	cout << "string find function" << nline;
	string a = "yash chaudhary";
	int x = a.find("aut");
	cout << x << nline;

	cout << nline;

	cout << "Set data structure" << nline;
	set<int> s;
	unordered_set<int> s1;
	s.insert(3);
	s.insert(5);
	s.insert(5);
	s.insert(1);
	s.insert(78);
	s.insert(4);
	int count = s.count(5);
	s.erase(3);
	cout << "count -> " << count << nline << nline;

	cout << "multiset and unordered_multiset" << nline;
	multiset<int> s2;
	s2.insert(9);
	s2.insert(9);
	s2.insert(7);
	s2.insert(4);
	s2.insert(65);
	s2.insert(1);
	for (int i : s2) cout << i << " ";

	cout << nline << nline;

	cout << "sort(all(x)) reverse(all(x)) random_shuffle(all(x))" << nline;
	cout << nline;



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