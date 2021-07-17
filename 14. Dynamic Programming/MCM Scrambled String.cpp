#include<bits/stdc++.h>
using namespace std;

bool mcm(string a, string b) {
  // base condition
  if (a.compare(b) == 0) return true;
  if (a.length() <= 1) return false;

  bool flag = false;

  for (int k = 0; k < a.length() - 1; k++) {
    bool a1 = mcm(a.substr(0, k + 1), b.substr(0, k + 1)) && mcm(a.substr(k + 1, a.length() - k - 1), b.substr(k + 1, a.length() - k - 1));
    bool a2 = mcm(a.substr(0, k + 1), b.substr(a.length() - k - 1, k + 1)) && mcm(a.substr(k + 1, a.length() - k - 1), b.substr(0,  a.length() - k - 1));
    if (a1 || a2) {
      flag = true;
      break;
    }
  }
  return flag;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    string a, b;
    cin >> a >> b;


    if (a.length() != b.length())
      cout << "Not a Scrambled String" << endl;
    else {
      if (mcm(a, b))
        cout << "Scrambled String" << endl;
      else
        cout << "Not a Scrambled String" << endl;
    }
  }

  return 0;
}