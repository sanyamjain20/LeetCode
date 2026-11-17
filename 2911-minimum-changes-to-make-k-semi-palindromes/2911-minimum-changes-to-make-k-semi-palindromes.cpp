class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        // cost[l][r] = minimum changes to make s[l..r] semi-palindromic
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int len = r - l + 1;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0)
                        continue;

                    int groups = len / d;
                    int changes = 0;

                    for (int j = 0; j < d; j++) {
                        int left = l + j;
                        int right = l + j + (groups - 1) * d;

                        for (int t = 0; t < groups / 2; t++) {
                            if (s[left + t * d] != s[right - t * d])
                                changes++;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        // dp[p][i] = minimum changes to partition first i characters
        // into exactly p substrings
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));

        dp[0][0] = 0;

        for (int p = 1; p <= k; p++) {
            for (int i = p; i <= n; i++) {
                for (int j = p - 1; j < i; j++) {
                    if (dp[p - 1][j] == INF)
                        continue;

                    dp[p][i] = min(
                        dp[p][i],
                        dp[p - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};