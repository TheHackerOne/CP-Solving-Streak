#include<bits/stdc++.h>
using namespace std;

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
	//code here.
	vector<int> ans;
	int i = 0, j = 0, k = 0;
	while ((i < n1) && (j < n2) && (k < n3)) {
		if ((A[i] == B[j]) && (B[j] == C[k])) {
			if (ans.size() != 0 && A[i] == ans[ans.size() - 1]) {
				i++, j++, k++;
				continue;
			}
			ans.push_back(A[i]);
			i++, j++, k++;
			continue;
		}
		int mini = min({A[i], B[j], C[k]});
		if (mini == A[i]) i++;
		if (mini == B[j]) j++;
		if (mini == C[k]) k++;
	}
	return ans;
}
