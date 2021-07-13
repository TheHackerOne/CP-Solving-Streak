#include<bits/stdc++.h>
using namespace std;

void printAll(int n, int oc, int cc, string output) {
  if (oc == 0 && cc == 0) {
    cout << output << endl;
    return;
  }
  if (oc == cc ) {
    printAll(n - 1, oc - 1, cc, output + "(");
  }  if (oc < cc && oc > 0 ) {
    printAll(n - 1, oc - 1, cc, output + "(");
  }  if (oc < cc && cc > 0 ) {
    printAll(n - 1, oc, cc - 1, output + ")");
  }
}

int main() {
  int n;
  string output;
  cin >> n;

  printAll(2 * n, n, n, output);

  return 0;
}