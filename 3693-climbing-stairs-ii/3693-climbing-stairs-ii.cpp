class Solution {
public:
    int solve(int n, vector<int>& costs, vector<int>& dp) {
        if (n == 0)
            return 0;

        if (dp[n] != INT_MAX)
            return dp[n];

        int ans = INT_MAX;

        if (n >= 1)
            ans = min(ans, solve(n - 1, costs, dp) + 1);

        if (n >= 2)
            ans = min(ans, solve(n - 2, costs, dp) + 4);

        if (n >= 3)
            ans = min(ans, solve(n - 3, costs, dp) + 9);

        return dp[n] = ans + costs[n - 1];
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        return solve(n, costs, dp);
    }
};