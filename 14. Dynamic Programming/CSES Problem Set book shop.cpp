// #include<bits/stdc++.h>

// using namespace std;

// #define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// #define MOD 1000000007
// #define MOD1 998244353
// #define INF 1e18
// #define nline "\n"
// #define pb push_back
// #define ppb pop_back
// #define mp make_pair
// #define ff first
// #define ss second
// #define PI 3.141592653589793238462
// #define set_bits __builtin_popcountll
// #define sz(x) ((int)(x).size())
// #define all(x) (x).begin(), (x).end()

// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double lld;

// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
// #else
// #define debug(x)
// #endif

// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("Error.txt", "w", stderr);
// #endif

// 	int n;
// 	cin >> n;

// 	char grid[n + 1][n + 1];
// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 1; j <= n; j++) {
// 			cin >> grid[i][j];
// 		}
// 	}
// 	int dp[n + 1][n + 1];
// 	memset(dp, 0, sizeof(dp));

// 	for (int i = n; i >= 1; i--) {
// 		for (int j = n; j >= 1; j--) {
// 			if (i == n && j == n) dp[i][j] = 1;
// 			else if (grid[i][j] == '*') {
// 				dp[i][j] = 0;
// 			}
// 			else {
// 				dp[i][j] = (((i + 1 > n) ? 0 : (dp[i + 1][j])) % MOD + ((j + 1 > n) ? 0 : (dp[i][j + 1])) % MOD) % MOD;
// 			}
// 		}
// 	}
// 	if (grid[1][1] == '*' || grid[n][n] == '*') cout << "0" << endl;
// 	else cout << dp[1][1] << endl;

// 	return 0;
// }

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

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int n, x;
	cin >> n >> x;

	vector<int> price(n + 1, 0);
	vector<int> pages(n + 1, 0);

	for (int i = 1; i <= n; i++) cin >> price[i];
	for (int i = 1; i <= n; i++) cin >> pages[i];

	int dp[n + 1][x + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			if (j == 0) {
				dp[i][j] = 0;
			} else {
				int opt1 = (j < price[i]) ? INT_MIN : (dp[i - 1][j - price[i]] + pages[i]);
				int opt2 = (i == 1) ? 0 : dp[i - 1][j];
				dp[i][j] = max(opt1, opt2);
			}
		}
	}

	cout << dp[n][x] << endl;

	return 0;
}