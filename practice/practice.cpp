#include<bits/stdc++.h>
using namespace std;

void ngtl(vector<int> &arr){
  stack<int> st;
  int n = arr.size();
  vector<int> res(n);

  for(int i=0;i<n;i++){
    while(!st.empty() and arr[i] >= st.top()) st.pop();
    if(st.empty()) res[i] = -1;
    else res[i] = st.top();
    st.push(arr[i]);
  }


  for(auto i:arr) cout<<i<<" ";
    cout<<endl;
  for(auto i:res) cout<<i<<" ";
    cout<<endl;
}

void rotate(){
  vector<int> arr = { 8, 3, 1, 7, 3, 2, 7 };

  ngtl(arr);
}

int main() {
#ifndef ONLINE_JUDGE  
    freopen("Error.txt", "w", stderr);
#endif

    int t;
    cin >> t;
    while (t--) {
        rotate();
    }

    return 0;
}