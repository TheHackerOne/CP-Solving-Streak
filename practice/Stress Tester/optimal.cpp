#include<iostream>
using namespace std;
int main(){int t;cin>>t;while(t--){
    int n,a[3000],val,s=0,ss=0;cin>>n;val=n;for(int i=0;i<n;i++)cin>>a[i],s+=a[i];
    for(int idx=0;idx<n;idx++){
        ss+=a[idx];if(!(s%ss)){
            int lav=1,l=idx+1,sss=0;while(l<n){
                sss+=a[l++];
                if(sss==ss)sss=0,lav++;}
            if(!sss)val=min(val,n-lav);}}
cout<<val<<endl;}return 0;}
