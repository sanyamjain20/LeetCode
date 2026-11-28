class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        
        vector<int> cnt(n + 1, 0);
        long long minPrice = 1e18;
        
        for (auto &x : items) {
            cnt[x[0]]++;
            minPrice = min(minPrice, (long long)x[1]);
        }
        
        vector<int> gain(n + 1, 0);
        
        for (int f = 1; f <= n; f++) {
            for (int j = f; j <= n; j += f) {
                gain[f] += cnt[j];
            }
            gain[f]--;
        }
        
        vector<pair<int, int>> good;
        
        for (auto &x : items) {
            int f = x[0];
            int p = x[1];
            
            if (gain[f] > 0 && 1LL * p < 2 * minPrice) {
                good.push_back({p, gain[f]});
            }
        }
        
        sort(good.begin(), good.end());
        
        long long ans = 0;
        long long b = budget;
        
        for (auto &[price, g] : good) {
            long long take = min((long long)g, b / price);
            ans += 2 * take;
            b -= take * price;
        }
        
        ans += b / minPrice;
        
        return ans;
    }
};