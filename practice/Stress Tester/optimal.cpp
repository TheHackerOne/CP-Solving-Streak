#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int mod=1000000007;
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

bool sq(int x){
  int i;
  for(i=1;i*i<=x;i++){

  }
  i--;
  if(i*i==x){
    return 1;
  }
  else return 0;
}
void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    int c[n];
    for(int i=0;i<n;i++){
      cin>>c[i];
    }
    int le[n+1]={0};
    for(int i=0;i<l;i++){
      le[c[i]]++;
    }

    int ri[n+1]={0};
    for(int i=l;i<n;i++){
      ri[c[i]]++;
    }

    //for 0 dollar
    for(int i=1;i<=n;i++){
        int val=min(le[i],ri[i]);
        le[i]=le[i]-val;
        ri[i]=ri[i]-val;
    }
    
    //for 1 dollar
    int a=0,b=0;
    for(int i=1;i<=n;i++){
        a+=le[i];
        b+=ri[i];
    }
    int cost=0;
    if(a>b){
        int rem=a-b;
        for(int i=1;i<=n;i++){
            if(le[i]>1){
                int temp=le[i];
                if(temp&1)temp--;
                if(rem>=temp){
                  rem-=temp;
                  if(le[i]&1)
                  le[i]=1;
                  else le[i]=0;
                  cost+=temp/2;
                }
                else{
                  cost+=rem/2;   
                  le[i]-=rem;
                  rem=0;
                }
            }
            if(rem==0)break;
        }
    }
    else if(b>a){
          int rem=b-a;
        for(int i=1;i<=n;i++){
            if(ri[i]>1){
                int temp=ri[i];
                if(temp&1)temp--;
                if(rem>=temp){
                  rem-=temp;
                  if(ri[i]&1)
                  ri[i]=1;
                  else ri[i]=0;
                  cost+=temp/2;
                }
                else{
                  cost+=rem/2;   
                  ri[i]-=rem;
                  rem=0;
                }
            }
            if(rem==0)break;
        }
    }

    a=0,b=0;
    for(int i=1;i<=n;i++){
      a+=le[i];
      b+=ri[i];
    }
    // cout<<cost<<endl;
    // for 1 dollar to shift from left to right
    int rem=abs(a-b);
    cost=cost+(rem/2);

    // cout<<cost<<endl;
    //again for 1 dollar
    cost=cost+((a+b)/2);


    cout<<cost;

    cout <<endl;
}
int32_t main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      // srand(time(0));
      int t;
      cin>>t;
      //   t=1;
      while(t--){
        // cout<<"Case #"<<tt<<": ";
            solve();
            // tt++;
      }
      return 0;
}