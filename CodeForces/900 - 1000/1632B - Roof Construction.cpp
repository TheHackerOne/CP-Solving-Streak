#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    ll t, n, i, j, m, c;
    
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        m=n-1;        
        c=0;
        
        while(m>0){
            c++;
            m/=2;
        }
        
        m=n-1;
        j=1;
        c--;
        
        while(c>0){
            j=j*2;
            c--;
        }
        
        for(i=m; i>=j; i--){
            cout<<i<<" ";
        }
        
        
        for(i=0; i<j; i++){
            cout<<i<<" ";
        }
        
        cout<<"\n";
    }
}