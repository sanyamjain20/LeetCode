class Solution {
public:
    const int MOD = 1e9 + 7;

    pair<int, int> getNext(int i, int j, int dir,
                           vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        while (i < m && j < n) {
            if (grid[i][j] == 0)
                return {i, j};

            if (dir == 0) {
                i++;
                dir = 1;
            } else {
                j++;
                dir = 0;
            }
        }

        return {-1, -1};
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<long long>>> dp(
            m, vector<vector<long long>>(n, vector<long long>(2, 0))
        );


        dp[0][0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    continue;

                for (int d = 0; d < 2; d++) {
                    long long ways = dp[i][j][d];

                    if (ways == 0)
                        continue;

                    auto p = getNext(i, j + 1, 0, grid);

                    if (p.first != -1) {
                        dp[p.first][p.second][0] =
                            (dp[p.first][p.second][0] + ways) % MOD;
                    }

                    p = getNext(i + 1, j, 1, grid);

                    if (p.first != -1) {
                        dp[p.first][p.second][1] =
                            (dp[p.first][p.second][1] + ways) % MOD;
                    }
                }
            }
        }

        return ((dp[m - 1][n - 1][0] +
                dp[m - 1][n - 1][1]) % MOD);
    }
};