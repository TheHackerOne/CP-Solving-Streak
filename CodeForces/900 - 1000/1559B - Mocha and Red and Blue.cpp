#include<bits/stdc++.h>
using namespace std;


void simple(string &str, int idx){
    for(int i=idx+1;i<str.length();i++){
        if(str[i] == '?'){
            if(str[i-1] == 'B') str[i] = 'R';
            else str[i] = 'B';            
        }
    }
}

void solve() {
    int n;
    cin>>n;
    string str;
    cin>>str;
    if(str.length() == 1){
        if(str[0] != '?'){
            cout<<str<<endl;
            return;
        }
        cout<<"R"<<endl;
        return;
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(str[i] == '?') count++;
    }
    if(count == n){
        char ch = 'B';
        int index = 0;
        while(index != n){
            str[index++] = ch;
            if(ch == 'B') ch = 'R';
            else ch = 'B';
        }
        cout<<str<<endl;
        return;
    }
    if(str[0] == '?'){
        int count = 0, idx = 0;
        while(str[idx] == '?') idx++,count++;
        if(str[idx] == 'R'){
            int index = 0;
            if(idx%2){
                // start with b
                char ch = 'B';
                while(index != idx){
                    str[index++] = ch;
                    if(ch == 'B') ch = 'R';
                    else ch = 'B';
                }
            }else{
                // start with r
                char ch = 'R';
                while(index != idx){
                    str[index++] = ch;
                    if(ch == 'B') ch = 'R';
                    else ch = 'B';
                }
            }
        }else if(str[idx] == 'B'){
            int index = 0;
            if(idx%2){
                // start with r
                char ch = 'R';
                while(index != idx){
                    str[index++] = ch;
                    if(ch == 'B') ch = 'R';
                    else ch = 'B';
                }
            }else{
                // start with b
                char ch = 'B';
                while(index != idx){
                    str[index++] = ch;
                    if(ch == 'B') ch = 'R';
                    else ch = 'B';
                }
            }
        }
        simple(str, idx);
    }else{
        simple(str, 0);
    }
    cout<<str<<endl;
}

int main() {
#ifndef ONLINE_JUDGE  
    freopen("Error.txt", "w", stderr);
#endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}