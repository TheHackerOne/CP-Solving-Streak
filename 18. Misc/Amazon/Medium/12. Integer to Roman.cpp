#include<bits/stdc++.h>

class Solution {
public:
    string intToRoman(int num) {
        vector<string> sign = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
        vector<int> value = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

        string ans = "";
        int idx = value.size()-1;

        while(num != 0){
         if((num/value[idx]) > 0){
             cout<<value[idx]<<endl;
             cout<<num<<endl;
            int times = num/value[idx];
            for(int i=0;i<times;i++){
               ans += sign[idx];
            }            
            num = num%value[idx];
         }
         idx--;
        }

        return ans;
    }
};