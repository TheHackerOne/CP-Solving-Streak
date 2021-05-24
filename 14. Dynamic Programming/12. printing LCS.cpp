#include<bits/stdc++.h>
using namespace std;

string LCS(string a, int sa, string b, int sb, string out) {
    if (sa == 0 || sb == 0) return out;

    if (a[sa - 1] == b[sb - 1])
        return LCS(a, sa - 1, b, sb - 1, out + a[sa - 1]);
    else {
        string s1 = LCS(a, sa - 1, b, sb, out);
        string s2 = LCS(a, sa, b, sb - 1, out);
        return s1.length() > s2.length() ? s1 : s2;
    }
}


int main() {
    string a, b, out;
    cin >> a >> b;

    cout << LCS(a, a.length(), b, b.length(), out);

    return 0;
}