#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    long long t,i,n,a,b,x,cur,s;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&a,&b);
        cur=0;
        s=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&x);
            s+=b*(x-cur);
            if((n-i)*b>=a)
            {
                s+=a*(x-cur);
                cur=x;
            }
        }
        printf("%lld\n",s);
    }
}