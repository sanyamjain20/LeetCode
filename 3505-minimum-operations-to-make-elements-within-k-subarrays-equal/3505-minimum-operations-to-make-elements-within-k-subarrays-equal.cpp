class Solution {
public:
    multiset<long long> lo, hi;
    long long sumLo = 0, sumHi = 0;

    void add(long long x) {
        if (lo.empty() || x <= *lo.rbegin()) {
            lo.insert(x);
            sumLo += x;
        } else {
            hi.insert(x);
            sumHi += x;
        }
        balance();
    }

    void remove(long long x) {
        auto it = lo.find(x);
        if (it != lo.end()) {
            sumLo -= x;
            lo.erase(it);
        } else {
            it = hi.find(x);
            sumHi -= x;
            hi.erase(it);
        }
        balance();
    }

    void balance() {
        while (lo.size() > hi.size() + 1) {
            auto it = prev(lo.end());
            long long x = *it;
            lo.erase(it);
            sumLo -= x;
            hi.insert(x);
            sumHi += x;
        }

        while (lo.size() < hi.size()) {
            auto it = hi.begin();
            long long x = *it;
            hi.erase(it);
            sumHi -= x;
            lo.insert(x);
            sumLo += x;
        }
    }

    long long getCost() {
        long long median = *lo.rbegin();

        return median * lo.size() - sumLo
             + sumHi - median * hi.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        if (1LL * x * k > n) return -1;

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; i++)
            add(nums[i]);

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);
            cost[i - x + 1] = getCost();
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(n + 1,
                                     vector<long long>(k + 1, INF));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];

                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};