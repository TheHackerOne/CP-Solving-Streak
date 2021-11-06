#include<bits/stdc++.h>
using namespace std;

int func(int x, int y, int l, int r){
    l--, r--;
    for(int i=l;i<=r;i++){
        int mask = 1;
        mask <<= i;
        if(y&mask){
            x = x|mask;
        }
    }
    return x;
}

int main(){
    cout<<func(10, 13,2 ,3);

    return 0;
}