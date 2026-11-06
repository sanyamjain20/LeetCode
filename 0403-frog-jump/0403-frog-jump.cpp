class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1)
            return false;
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        dp[1][1] = true;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        for (int i = 1; i < n - 1; i++) {
            for (int k = 1; k < n; k++) {
                if (dp[i][k]) {
                    for (int j = k - 1; j <= k + 1; j++) {
                        if (j == 0)
                            continue;
                        if (mp.find(stones[i] + j) != mp.end()) {
                            int nexpos = mp[stones[i] + j];
                            dp[nexpos][j] = true;
                        }
                    }
                }
            }
        }
        for (int k = 1; k < n; k++) {
            if (dp[n - 1][k])
                return true;
        }
        return false;
    }
};