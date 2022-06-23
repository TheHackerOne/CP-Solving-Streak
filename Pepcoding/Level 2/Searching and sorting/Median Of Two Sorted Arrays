#include<bits/stdc++.h>
using namespace std;

float solve(vector<float> &a, vector<float> &b){
    int n = a.size(), m = b.size();
    int totalElements = n + m;

    if(n > m) return solve(b, a);

    int lo = 0, hi = a.size();
    while(lo <= hi){
        int elementsFromArr1 = (lo + hi)/2;
        int elementsFromArr2 = ((totalElements+1)/2) - elementsFromArr1;
        // cout<<"e1 -> "<<elementsFromArr1<<endl;
        // cout<<"e2 -> "<<elementsFromArr2<<endl;

        float left1 = elementsFromArr1 > 0 ? a[elementsFromArr1-1] : INT_MIN;
        float left2 = elementsFromArr2 > 0 ? b[elementsFromArr2-1] : INT_MIN;
        float right1 = elementsFromArr1 < n ? a[elementsFromArr1] : INT_MAX;
        float right2 = elementsFromArr2 < m ? b[elementsFromArr2] : INT_MAX;
        // cout<<elementsFromArr1<<endl;            
        // cout<<left1<<" "<<left2<<" "<<right1<<" "<<right2<<endl;
        if(left1 > right2){
            hi = elementsFromArr1-1;
        }else if(left2 > right1){
            lo = elementsFromArr1+1;
        }else{
            if(totalElements%2) {
                return max(left1, left2);
            }else{
                // cout<<left1<<" "<<left2<<" "<<right1<<" "<<right2<<endl;
                return (max(left1, left2)*1.0 + min(right1, right2)*1.0)/2.0;
            }
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<float> arr1(n);

    for(int i=0;i<n;i++) cin>>arr1[i];

    int m;
    cin>>m;
    vector<float> arr2(m);

    for(int i=0;i<m;i++) cin>>arr2[i];

    int median = solve(arr1, arr2);
    int ab=median*10;
    string ans=to_string(ab);
    int k=ans.length();
    if(ans[k-1]=='0') cout<<median<<".0";
    else cout<<median;

    return 0;
}
