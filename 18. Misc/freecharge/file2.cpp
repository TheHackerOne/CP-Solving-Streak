// str = "abccccdd"
// Output: 7

// // odd
// c = 3
// a = 3 (2)
// b = 1 

// // even
// d = 2

// "adcccda"

#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    // abccccdd
    // count each alpha occurence
    unordered_map<char, int> mp;
    for(int i=0;i<str.length();i++){
        mp[str[i]]++;
    }

    unordered_map<char, int> oddCount, evenCount;
    vector<pair<char, int>> arr;

    for(auto i:mp){
        int cnt = i.second;
        char ch = i.first;
        if(cnt%2 == 0) evenCount[ch] = cnt;
        else oddCount[ch] = cnt;
    }

    for(auto i:oddCount){
        char ch = i.first, cnt = i.second;
        arr.push_back({ ch, cnt });
    }

    sort(arr.begin(), arr.end(), [](pair<char, int> &a, pair<char, int> &b){
        return a.second > b.second;
    });
    // a = 7, b= 3, c = 5
    // { (a,7), (c, 5), (b, 3) }

    string longestPalindrome = "";

    for(auto i:evenCount){
        char ch = i.first, cnt = i.second;
        for(int j=0;j<cnt/2;j++) longestPalindrome += ch;
        for(int j=0;j<cnt/2;j++) longestPalindrome = ch + longestPalindrome;
    }


// str = "abccccdd"
// Output: 7

// // odd
// c = 3 (2'c) 
// a = 3 (2)
// b = 1 

    for(int i=0;i<arr.size();i++){
        char ch = arr[i].first;
        int cnt = arr[i].second;

        if(i == 0){
            int newCnt = cnt-1;
            for(int j=0;j<newCnt/2;j++) longestPalindrome += ch;
            for(int j=0;j<newCnt/2;j++) longestPalindrome = ch + longestPalindrome;
            int len = longestPalindrome.length();
            string ans = longestPalindrome.substr(0, len/2) + ch + longestPalindrome.substr(len/2);
            longestPalindrome = ans;
        }else{
            if(cnt == 1) break;
            else{
                int newCnt = cnt-1;
                for(int j=0;j<newCnt/2;j++) longestPalindrome += ch;
                for(int j=0;j<newCnt/2;j++) longestPalindrome = ch + longestPalindrome;
            }
        }
    }

    cout<<longestPalindrome<<endl;


    return 0;
}





