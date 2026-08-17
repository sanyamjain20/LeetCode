class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);
        int sum;
        for (int i = n - 1; i >= 0; i--) {
            sum = 0;
            dp[i] = INT_MIN;
            for (int x = 1; x <= 3 && i + x <= n; x++) {
                sum += stoneValue[i + x - 1];
                dp[i] = max(dp[i], sum - dp[i + x]);
            }
        }
        if (dp[0] == 0)
            return "Tie";
        else if (dp[0] < 0)
            return "Bob";
        return "Alice";
    }
};