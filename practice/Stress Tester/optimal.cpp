#include <bits/stdc++.h>
using namespace std;
pair <int,int> a[200001];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k=0,sum=0;
        for(k=1;k<=n;k++)cin>>a[k].first;
        for(k=1;k<=n;k++)cin>>a[k].second;
        sort(a+1,a+n+1);
        k=n;
        while(sum<=a[k].first&&k>=1){
            sum+=a[k].second;
            k--;
        }
        cout<<min(a[k+1].first,sum)<<endl;
    }
    return 0;
}