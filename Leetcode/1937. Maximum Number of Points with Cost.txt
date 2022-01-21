class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long rows = points.size();
        long long columns = points[0].size();

        long long dp[rows][columns];

        for (long long i = 0; i < columns; i++) {
            dp[0][i] = points[0][i];
        }

        for (long long i = 1; i < rows; i++) {
            long long left[columns];
            left[0] = dp[i - 1][0];
            for (long long j = 1; j < columns; j++) {
                left[j] = max(left[j - 1], dp[i - 1][j] + j);
            }

            long long right[columns];
            right[columns - 1] = dp[i - 1][columns - 1] - (columns - 1);
            for (long long j = columns - 2; j >= 0; j--) {
                right[j] = max(right[j + 1], dp[i - 1][j] - j);
            }

            for (long long j = 0; j < columns; j++) {
                dp[i][j] = max(left[j] - j, right[j] + j) + points[i][j];
            }
        }
        long long maxSum = INT_MIN;
        for (long long i = 0; i < columns; i++) {
            maxSum = max(maxSum, dp[rows - 1][i]);
        }
        return maxSum;

    }
};