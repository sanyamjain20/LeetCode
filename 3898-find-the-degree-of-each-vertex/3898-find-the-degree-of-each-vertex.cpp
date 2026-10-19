class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            for (int& e : matrix[i]) {
                if (e)
                    ans[i]++;
            }
        }
        return ans;
    }
};