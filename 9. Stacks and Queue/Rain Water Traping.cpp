class Solution {
public:

    void output(vector<int> &v) {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    int trap(vector<int>& height) {
        vector<int> l, r;

        int lMax = INT_MIN;

        for (int i = 0; i < height.size(); i++) {
            if (lMax == INT_MIN || lMax < height[i])
                l.push_back(height[i]);
            else {
                l.push_back(lMax);
            }
            lMax = max(lMax, height[i]);
        }

        int rMax = INT_MIN;

        for (int i = height.size() - 1; i >= 0; i--) {
            if (rMax == INT_MIN || rMax < height[i])
                r.push_back(height[i]);
            else {
                r.push_back(rMax);
            }
            rMax = max(rMax, height[i]);
        }
        reverse(r.begin(), r.end());

        int water = 0;
        for (int i = 0; i < height.size(); i++) {
            water += (min(r[i], l[i]) - height[i]);
        }

        return water;

    }
};