#include<bits/stdc++.h>
using namespace std;

// next greatest element to left
vector<int> NGL(int *arr, int n) {
  stack<int> s;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (s.empty()) ans.push_back(-1);

    if (s.size() > 0 && s.top() > arr[i]) {
      ans.push_back(s.top());
    }

    if (s.size() > 0 && s.top() <= arr[i]) {
      while (s.size() > 0 && s.top() <= arr[i]) {
        s.pop();
      }
      if (s.empty()) ans.push_back(-1);
      else ans.push_back(s.top());
    }

    s.push(arr[i]);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++) cin >> arr[i];

  vector<int> ans = NGL(arr, n);

  for (int i : arr) cout << i << " ";

  cout << endl;

  for (int i : ans) cout << i << " ";

  return 0;
}