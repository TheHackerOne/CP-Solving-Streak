#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i,n) for(int i=0;i<n;i++)
#define rl(i,m,n) for(int i=n;i>=m;i--)
#define py cout<<"YES\n";
#define pm cout<<"-1\n";
#define pn cout<<"NO\n";
#define pi 3.141592653589793238
#define vr(v) v.begin(),v.end()
#define rv(v) v.end(),v.begin()
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Asquare cout.tie(NULL);
using namespace std;
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}
void printarr(ll arr[], ll n){fl(i,n) cout << arr[i] << " ";cout << "\n";}
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
vector<int> primees(10000000,1);vector<int> anses(10000000,0);
// ll mx=LONG_LONG_MIN;ll mn=LONG_LONG_MAX;
void isPrimes(){int c=0;for (int p = 2; p * p <= 10000000; p++)if (primees[p] == 1)for (int i = p * 2; i <= 10000000; i += p){primees[i] = 0;}for (int p = 2; p <= 10000000; p++){anses[p]=anses[p-1]+primees[p];}}
ll productOfSubsetSums(ll arr[], ll n,ll mod){ll ans = 1;for (int i = 0; i < n; ++i )ans = ((ans%mod) * ((arr[i] + 1)%mod))%mod;return ans-1;}
typedef pair<ll, ll> pll;
//Code by Abhinav Awasthi
//Language C++
//Practice->Success
void asquare()
{
    ll n;
    cin>>n;
    vector<lld>arr(n);
    fl(i,n)cin>>arr[i];
    lld d,a;
    ll c=2;
    ll ans=0;
    if(n==1||n==2){cout<<"0\n";return;}
    fl(i,n)
    {
        for(int j=i+1;j<n;j++)
        {
            if(j==i)continue;
            else
            {
                d=(arr[j]-arr[i]);
                a=arr[i]-((lld)(i)*d/(j-i));
                for(int k=0;k<n;k++)
                {
                    if(k==i||k==j)continue;
                    else if(arr[k]==a+(k*d/(j-i)))c++;
                }
                ans=max(ans,c);
                c=2;
            }
        }
    }
    reverse(vr(arr));
    fl(i,n)
    {
        for(int j=i+1;j<n;j++)
        {
            if(j==i)continue;
            else
            {
                d=(arr[j]-arr[i]);
                a=arr[i]-((lld)(i)*d/(j-i));
                for(int k=0;k<n;k++)
                {
                    if(k==i||k==j)continue;
                    else if(arr[k]==a+(k*d/(j-i)))c++;
                }
                ans=max(ans,c);
                c=2;
            }
        }
    }
    cout<<n-ans<<"\n";
}
int main()
{
    Code By Asquare
    ll t;
    cin>>t;
    while(t--)
    {
        asquare();
    }
    // asquare();
    return 0;
}