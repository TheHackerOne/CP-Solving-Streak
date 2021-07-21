class Solution {
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

    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int> nsl = NSL(heights, size);
        vector<int> nsr = NSR(heights, size);
        vector<int> width;
        for (int i = 0; i < size; i++) {
            width.push_back(nsr[i] - nsl[i] - 1);
        }

        int maxW = INT_MIN;
        for (int i = 0; i < size; i++) {
            maxW = max(maxW, width[i] * heights[i]);
        }
        return maxW;
    }
};