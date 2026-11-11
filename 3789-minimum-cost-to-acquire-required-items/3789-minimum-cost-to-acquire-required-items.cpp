class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long ans = 0;

        long long common = min(need1, need2);

        ans += common * min(cost1 + cost2, costBoth);

        if (need1 < need2)
            ans += (long long)(need2 - need1) * min(cost2, costBoth);
        else
            ans += (long long)(need1 - need2) * min(cost1, costBoth);

        return ans;
    }
};