#include<bits/stdc++.h>
using namespace std;


int evaluate(int lt, int lf, int rt, int rf, char b, char s) {
  int trueOne = lt;
  int falseOne = lf;
  int trueSecond = rt;
  int falseSecond = rf;

  int ans = 1;

  if (b == 'T') {
    if (s == '|') {
      ans = (trueOne * trueSecond) + (trueOne * falseSecond) + (falseOne * trueSecond);
    } else if (s == '&') {
      ans = trueOne * trueSecond;
    } else if (s == '^') {
      ans = (trueOne * falseSecond) + (falseOne * trueSecond);
    }
  } else if (b == 'F') {
    if (s == '|') {
      ans = (falseOne * falseSecond);
    } else if (s == '&') {
      ans = (trueOne * falseSecond) + (falseOne * trueSecond) + (falseOne * falseSecond);
    } else if (s == '^') {
      ans = (trueOne * trueSecond) + (falseOne * falseSecond);
    }
  }
  return ans;
}

int mcm(string s, int l, int r, char b) {
  if (l == r) {
    if (b == 'T' && s[l] == 'T') return 1;
    else if (b == 'F' && s[l] == 'F') return 1;
    else return 0;
  }

  int ans = 0;

  for (int k = l + 1; k < r; k += 2) {
    int lt = mcm(s, l, k - 1, 'T');
    int lf = mcm(s, l, k - 1, 'F');
    int rt = mcm(s, k + 1, r, 'T');
    int rf = mcm(s, k + 1, r, 'F');
    ans += evaluate(lt, lf, rt, rf, b, s[k]);
  }
  return ans;
}

int main() {
  string s;
  cin >> s;

  cout << mcm(s, 0, s.length() - 1, 'T') << endl;

  return 0;
}