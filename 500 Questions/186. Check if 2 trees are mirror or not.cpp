class Solution {
public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        vector<int> ap, ac, bp, bc;
        for (int i = 0; i < 2 * e; i++) {
            if (i % 2 == 0) ap.push_back(A[i]);
            else ac.push_back(A[i]);
        }
        for (int i = 0; i < 2 * e; i++) {
            if (i % 2 == 0) bp.push_back(B[i]);
            else bc.push_back(B[i]);
        }
        unordered_map<int, stack<int>> mp;

        for (int i = 0; i < ap.size(); i++) {
            mp[ap[i]].push(ac[i]);
        }
        for (int i = 0; i < bp.size(); i++) {
            if (mp[bp[i]].top() != bc[i]) return 0;
            mp[bp[i]].pop();
        }
        return 1;
    }
};