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

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = (ll(i) * ll(i)); j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void precision(int a) {cout << setprecision(a) << fixed;}
/*--------------------------------------------------------------------------------------------------------------------------*/

bool comp(pair<ll, ll> &a,pair<ll, ll> &b){
    return a.first < b.first;
}

bool comp2(pair<ll, ll> &a,pair<ll, ll> &b){
    return a.second < b.second;
}

void solve() {
    ll w, h;
    cin>>w>>h;
    ll n1, n2, n3, n4;
    cin>>n1;
    vector<pair<ll, ll>> down;
    for(ll i=0;i<n1;i++){
        ll a; 
        cin>>a;
        down.push_back({ a, 0 });
    }
    cin>>n2;
    vector<pair<ll, ll>> up;
    for(ll i=0;i<n2;i++){
        ll a; 
        cin>>a;
        up.push_back({ a, h });
    }
    cin>>n3;
    vector<pair<ll, ll>> left;
    for(ll i=0;i<n3;i++){
        ll a; 
        cin>>a;
        left.push_back({ 0, a });
    }
    cin>>n4;
    vector<pair<ll, ll>> right;
    for(ll i=0;i<n4;i++){
        ll a; 
        cin>>a;
        right.push_back({ w, a });
    }
    sort(all(down), comp);
    sort(all(up), comp);
    sort(all(left), comp2);
    sort(all(right), comp2);
    ll a1 = h*abs(down[0].first-down[n1-1].first) ; // base
    ll a2 = h*abs(up[0].first-up[n2-1].first) ; // up
    ll a3 = w*abs(left[0].second-left[n3-1].second) ; // left
    ll a4 = w*abs(right[0].second-right[n4-1].second) ; // right
    cout<<max({a1,a2,a3,a4})<<nline;
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