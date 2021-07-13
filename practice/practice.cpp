#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int disks, char src, char dest, char hel) {
  if (disks == 1) {
    cout << "disk " << disks << " from " << src << " to " << dest << endl;
    return;
  }
  towerOfHanoi(disks - 1, src, hel, dest);

  cout << "disk " << disks << " from " << src << " to " << dest << endl;

  towerOfHanoi(disks - 1, hel, dest, src);
}

int main() {
  int disks;
  cin >> disks;

  char s = 's';
  char d = 'd';
  char h = 'h';

  towerOfHanoi(disks, s, d, h);

  return 0;
}