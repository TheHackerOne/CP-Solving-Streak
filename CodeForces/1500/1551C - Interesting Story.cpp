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
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
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


void solve() {
    int n;
    cin>>n;

    vector<string> arr(n);
    unordered_map<string, unordered_map<char, int>> mp2;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        unordered_map<char, int> mp1;
        for(auto &ch:arr[i]){
            mp1[ch]++;
        }
        mp2[arr[i]] = mp1;
    }

    // focuses on "a"
    sort(all(arr), [&mp2](string &str1, string &str2){
        int remCh1 = str1.length()-mp2[str1]['a'];
        int remCh2 = str2.length()-mp2[str2]['a'];
        return (mp2[str1]['a']-remCh1) > (mp2[str2]['a']-remCh2);
        // if(rat1 == 0.0 and rat2 == 0.0) return str1.length() < str2.length();
        // return rat1 > rat2;
    });
    // debug(arr)
    int res1 = 0, rem = 0;
    int remcnt = 0;
    int cnt = 0;
    for(auto &str:arr){
        int curra = mp2[str]['a'], currRem = str.length()-mp2[str]['a'];
        if(res1+curra > rem+currRem){
            res1 += curra;
            rem += currRem;
            cnt++;
        }
    }
    res1 = cnt;

    // debug(res1)
    // debug(rem)

    // focuses on "b"
    sort(all(arr), [&mp2](string &str1, string &str2){
        int remCh1 = str1.length()-mp2[str1]['b'];
        int remCh2 = str2.length()-mp2[str2]['b'];
        return (mp2[str1]['b']-remCh1) > (mp2[str2]['b']-remCh2);
        // if(rat1 == 0.0 and rat2 == 0.0) return str1.length() < str2.length();
        // return rat1 > rat2;
    });

    // debug(arr)
    int res2 = 0, rem2 = 0;
    int remcnt2 = 0;
    cnt = 0;
    for(auto &str:arr){
        int curra = mp2[str]['b'], currRem = str.length()-mp2[str]['b'];
        if(res2+curra > rem2+currRem){
            res2 += curra;
            rem2 += currRem;
            cnt++;
        }
    }
    res2 = cnt;

    // debug(res2)
    // debug(rem2)

    // focuses on "c"
    sort(all(arr), [&mp2](string &str1, string &str2){
        int remCh1 = str1.length()-mp2[str1]['c'];
        int remCh2 = str2.length()-mp2[str2]['c'];
        return (mp2[str1]['c']-remCh1) > (mp2[str2]['c']-remCh2);
        // if(rat1 == 0.0 and rat2 == 0.0) return str1.length() < str2.length();
        // return rat1 > rat2;
    });
    // debug(arr)
    int res3 = 0, rem3 = 0;
    int remcnt3 = 0;
    cnt = 0;
    for(auto &str:arr){
        int curra = mp2[str]['c'], currRem = str.length()-mp2[str]['c'];
        if(res3+curra > rem3+currRem){
            res3 += curra;
            rem3 += currRem;
            cnt++;
        }
    }
    res3 = cnt;

    // debug(res3)
    // debug(rem3)

    // focuses on "d"
    sort(all(arr), [&mp2](string &str1, string &str2){
        int remCh1 = str1.length()-mp2[str1]['d'];
        int remCh2 = str2.length()-mp2[str2]['d'];
        return (mp2[str1]['d']-remCh1) > (mp2[str2]['d']-remCh2);
        // if(rat1 == 0.0 and rat2 == 0.0) return str1.length() < str2.length();
        // return rat1 > rat2;
    });
    // debug(arr)
    int res4 = 0, rem4 = 0;
    int remcnt4 = 0;
    cnt = 0;
    for(auto &str:arr){
        int curra = mp2[str]['d'], currRem = str.length()-mp2[str]['d'];
        if(res4+curra > rem4+currRem){
            res4 += curra;
            rem4 += currRem;
            cnt++;
        }
    }
    res4 = cnt;

    // debug(res4)
    // debug(rem4)

    // focuses on "e"
    sort(all(arr), [&mp2](string &str1, string &str2){
        int remCh1 = str1.length()-mp2[str1]['e'];
        int remCh2 = str2.length()-mp2[str2]['e'];
        return (mp2[str1]['e']-remCh1) > (mp2[str2]['e']-remCh2);
        // if(rat1 == 0.0 and rat2 == 0.0) return str1.length() < str2.length();
        // return rat1 > rat2;
    });

    // debug(arr)
    int res5 = 0, rem5 = 0;
    int remcnt5 = 0;
    cnt = 0;
    for(auto &str:arr){
        int curra = mp2[str]['e'], currRem = str.length()-mp2[str]['e'];
        if(res5+curra > rem5+currRem){
            res5 += curra;
            rem5 += currRem;
            cnt++;
        }
    }
    res5 = cnt;

    // debug(res5)
    // debug(rem5)

    cout<<max({ res1, res2, res3, res4, res5 })<<nline;

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