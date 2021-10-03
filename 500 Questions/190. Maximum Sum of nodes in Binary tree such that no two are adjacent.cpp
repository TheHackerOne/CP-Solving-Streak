class Solution {
public:
    //Function to return the maximum sum of non-adjacent nodes.
    class Pair {
    public:
        int selectSum = 0;
        int unselectSum = 0;
    };
    Pair getMaxSumHelper(Node *root) {
        // base case
        if (root == nullptr) {
            Pair p;
            return p;
        }

        // main logic
        Pair left = getMaxSumHelper(root -> left);
        Pair right = getMaxSumHelper(root -> right);
        Pair ans;
        ans.selectSum = root -> data + left.unselectSum + right.unselectSum;
        ans.unselectSum = max(left.selectSum, left.unselectSum) + max(right.selectSum, right.unselectSum);
        return ans;
    }

    int getMaxSum(Node *root)
    {
        // Add your code here
        Pair p = getMaxSumHelper(root);
        return max(p.selectSum, p.unselectSum);
    }
};