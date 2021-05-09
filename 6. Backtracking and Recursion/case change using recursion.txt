#include<bits/stdc++.h>
using namespace std;

void caseChangeRecursion(string input, int i, string output) {
	if (input[i] == '\0') {
		cout << output << endl;
		return;
	}
	string out1, out2;
	out1 = output + input[i];
	char x = toupper(input[i]);
	out2 = output + x;
	caseChangeRecursion(input, i + 1, out1);
	caseChangeRecursion(input, i + 1, out2);
}

int main() {
	string input, output;
	cin >> input;

	caseChangeRecursion(input, 0, output);

	return 0;
}