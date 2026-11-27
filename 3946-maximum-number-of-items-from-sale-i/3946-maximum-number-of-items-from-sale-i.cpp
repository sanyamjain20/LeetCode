class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> dp(budget + 1, 0);
        
        int mn = INT_MAX;
        
        for (auto &item : items) {
            int f = item[0];
            int p = item[1];
            
            mn = min(mn, p);
            
            int value = 0;
            for (auto &x : items) {
                if (x[0] % f == 0)
                    value++;
            }
            
            for (int j = budget; j >= p; j--) {
                dp[j] = max(dp[j], dp[j - p] + value);
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i <= budget; i++) {
            ans = max(ans, dp[i] + (budget - i) / mn);
        }
        
        return ans;
    }
};