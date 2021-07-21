class Solution {
    // https://leetcode.com/problems/maximal-rectangle/submissions/
public:

    vector<int> NSL(vector<int> &h, int n) {
        vector<int> ans;
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (s.empty()) ans.push_back(-1);

            if (s.size() > 0 && h[s.top()] < h[i]) {
                ans.push_back(s.top());
            }

            if (s.size() > 0 && h[s.top()] >= h[i]) {
                while (s.size() > 0 && h[s.top()] >= h[i]) {
                    s.pop();
                }
                if (s.empty()) ans.push_back(-1);
                else ans.push_back(s.top());
            }

            s.push(i);
        }
        return ans;
    }

    vector<int> NSR(vector<int> &h, int n) {
        vector<int> ans;
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) ans.push_back(n);

            if (s.size() > 0 && h[s.top()] < h[i]) {
                ans.push_back(s.top());
            }

            if (s.size() > 0 && h[s.top()] >= h[i]) {
                while (s.size() > 0 && h[s.top()] >= h[i]) {
                    s.pop();
                }

                if (s.empty()) ans.push_back(n);
                else ans.push_back(s.top());
            }

            s.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0  ) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int maxW = INT_MIN;

        vector<int> curr(cols, 0);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] != '0')
                    curr[j] += (matrix[i][j] - '0');
                else curr[j] = 0;
            }

            vector<int> nsl = NSL(curr, cols);
            vector<int> nsr = NSR(curr, cols);
            vector<int> width;
            for (int i = 0; i < cols; i++)
                width.push_back(nsr[i] - nsl[i] - 1);


            for (int i = 0; i < cols; i++)
                maxW = max(maxW, width[i] * curr[i]);

        }

        return maxW;

    }
};