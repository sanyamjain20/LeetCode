class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int X = 1024;

        vector<vector<bitset<X>>> dp(n, vector<bitset<X>>(m));

        dp[0][0].set(grid[0][0]);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;

                for (int x = 0; x < X; x++) {
                    if (i > 0 && dp[i - 1][j][x])
                        dp[i][j].set(x ^ grid[i][j]);

                    if (j > 0 && dp[i][j - 1][x])
                        dp[i][j].set(x ^ grid[i][j]);
                }
            }
        }

        for (int x = 0; x < X; x++) {
            if (dp[n - 1][m - 1][x])
                return x;
        }

        return -1;
    }
};