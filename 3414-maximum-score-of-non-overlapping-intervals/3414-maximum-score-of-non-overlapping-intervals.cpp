class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> ids;
    };

    State better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score ? a : b;
        return a.ids < b.ids ? a : b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end());

        vector<long long> left(n);

        for (int i = 0; i < n; i++)
            left[i] = a[i][0];

        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(
                left.begin(),
                left.end(),
                a[i][1]
            ) - left.begin();
        }

        vector<array<State, 5>> dp(n + 1);

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                State skip = dp[i + 1][k];

                State take = dp[nxt[i]][k - 1];
                take.score += a[i][2];

                int id = a[i][3];

                take.ids.insert(
                    lower_bound(take.ids.begin(), take.ids.end(), id),
                    id
                );

                dp[i][k] = better(skip, take);
            }
        }

        return dp[0][4].ids;
    }
};