class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp = prices;
        vector<int> preMin(n);
        preMin[0] = INT_MAX;
        for (int i = 1; i < n; i++) {
            preMin[i] = min(preMin[i - 1], prices[i - 1]);
        }
        for (int i = 0; i < n; i++) {
            dp[i] -= preMin[i];
            if(dp[i]<0)dp[i]=0;
        }
        return *max_element(dp.begin(), dp.end());
    }
};