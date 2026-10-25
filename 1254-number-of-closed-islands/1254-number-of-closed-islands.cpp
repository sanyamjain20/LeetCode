class Solution {
public:
    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int r,
             int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
            return false;

        if (grid[r][c] == 1 || visited[r][c])
            return true;
        if (r == 0 || c == 0 || r == grid.size() - 1 || c == grid[0].size() - 1)
            return false;
        visited[r][c] = 1;

        return dfs(grid, visited, r - 1, c) & dfs(grid, visited, r + 1, c) &
               dfs(grid, visited, r, c - 1) & dfs(grid, visited, r, c + 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    if (dfs(grid, visited, i, j))
                        ans++;
                }
            }
        }

        return ans;
    }
};