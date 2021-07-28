#include<bits/stdc++.h>
using namespace std;

int search(string pat, string txt) {
    unordered_map<char, int> mp;
    for (auto i : pat)
        mp[i]++;

    int i = 0, j = 0, count = mp.size(), ans = 0;
    while (j < txt.length()) {
        // calculation
        if (mp.find(txt[j]) != mp.end()) {
            mp[txt[j]]--;
            if (mp[txt[j]] == 0) count--;
        }
        int eleCount = j - i + 1;
        // first statement
        if (eleCount < pat.length()) {
            j++;
        } else if (eleCount == pat.length()) {
            if (count == 0)  ans++;
            if (mp.find(txt[i]) != mp.end()) {
                mp[txt[i]]++;
                if (mp[txt[i]] == 1) count++;
            }

            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    string txt, pat;
    cin >> txt >> pat;

    cout << search(pat, txt);

    return 0;
}