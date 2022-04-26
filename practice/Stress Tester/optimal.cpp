#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
long long t,n,m=0,s=1,b,ans=1;
void se(){
    map<int,int> a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b;
        a[b]++;
        ans=ans*i%mod;
        if(b>m) m=b;
    }
    if(a[m]>1) cout<<ans<<endl;
    else{
        for(int i=1;i<=n;i++)
            if(i!=a[m-1]+1) s=s*i%mod;
        cout<<(ans-s+mod)%mod<<endl;    
    }
    m=0,s=1,ans=1;
}
int main(){
    cin>>t;
    while(t--) se();
    return 0;
}
