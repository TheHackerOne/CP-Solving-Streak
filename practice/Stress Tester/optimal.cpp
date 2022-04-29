#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fun(ll curr,ll n,ll b)
{
        ll count;
        count=(n-curr*b)*curr;
        return count;
}
int main()
{
    ll n,b;
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        ll count=0;
        ll max=-1;
        cin>>n>>b;
        if(n<=b)
        {
            cout<<0<<endl;
            continue;
        }
        ll curr=2;
        count+=(n-b);
        max=count;
        //cout<<max<<endl;
        ll lo = 1,hi=n/b,mid1,mid2,h=0;
        ll ans;
        while(lo < hi) {
    int mid = (lo + hi) >> 1;
    if(fun(mid,n,b) > fun(mid+1,n,b)) {
        hi = mid;
    }
    else {
        lo = mid+1;
    }
}

        /*while(h<200)
        {
            mid1=lo+(hi-lo)/3;
            mid2=hi-(hi-lo)/3;
            if(fun(mid1,n,b)>fun(mid2,n,b))
                hi=mid2;
            else
                lo=mid1;
            h++;
        }*/
        ans=lo;

        /*while(1)
        {

            count=(n-curr*b)*curr;
            if(count<0)
                break;
            if(max<count)
                max=count;
            cout<<count<<endl;
            curr++;
        }*/

        cout<<fun(ans,n,b)<<endl;
    }
    return 0;
}
