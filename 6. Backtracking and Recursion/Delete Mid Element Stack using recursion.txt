#include<bits/stdc++.h>

using namespace std;

void DeleteMidElementStack(stack<int> &s, int size, int midIndex) {
	if (midIndex == size - 1) {
		s.pop();
		return;
	}
	int value = s.top();
	s.pop();
	DeleteMidElementStack(s, size - 1, midIndex);
	s.push(value);
}

void printStack(stack<int> s) {
	while (s.size() != 0) {
		cout << s.top() << " ";
		s.pop();
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	stack<int> s;
	s.push(6);
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	printStack(s);
	cout << endl;

	int mid = (s.size() - 1) / 2;

	DeleteMidElementStack(s, s.size(), mid);

	printStack(s);

	return 0;
}