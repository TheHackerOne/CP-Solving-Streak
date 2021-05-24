#include<bits/stdc++.h>
using namespace std;

string printSCS(string a, int sa, string b, int sb, string out) {
    if (sa == 0 && sb == 0) return out;
    if (sa == 0 && sb != 0) return out + b.substr(0, sb);
    if (sa != 0 && sb == 0) return out + a.substr(0, sa);

    if (a[sa - 1] == b[sb - 1])
        return printSCS(a, sa - 1, b, sb - 1, out + a[sa - 1]);
    else {
        string s1 = printSCS(a, sa - 1, b, sb, out + a[sa - 1]);
        string s2 = printSCS(a, sa, b, sb - 1, out + b[sb - 1]);
        return s1.length() < s2.length() ? s1 : s2;
    }
}


int main() {
    string a, b, out;
    cin >> a >> b;

    cout << printSCS(a, a.length(), b, b.length(), out);

    return 0;
}