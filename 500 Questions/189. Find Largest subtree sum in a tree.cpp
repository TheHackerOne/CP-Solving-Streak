#include<bits/stdc++.h>
using namespace std;

class Solution
{
	class Node {
	public:
		int data;
		Node *left = nullptr;
		Node *right = nullptr;
	};

public:
	int max_sum = INT_MIN;
	int maxSumHelper(Node *root) {
		// base case
		if (root == nullptr) {
			return 0;
		}
		// main logic
		int left = maxSumHelper(root -> left);
		int right = maxSumHelper(root -> right);
		int currSum = left + right + root -> data;
		if (currSum > max_sum) {
			max_sum = currSum;
		}
		return currSum;
	}

	int maxSum(Node *root) {
		return maxSumHelper(root);
	}
};