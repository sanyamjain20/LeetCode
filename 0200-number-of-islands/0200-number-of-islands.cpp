class Solution {
public:
    void dfs(vector<vector<char>> & grid,  vector<vector<int>> & vis, int r,
             int c) {
        int n = grid.size();
        int m = grid[0].size();
        if (r < 0 || r >= n || c < 0 || c >= m || vis[r][c] != 0 ||
            grid[r][c] == '0')
            return;
        vis[r][c] = 1;
        dfs(grid, vis, r + 1, c);
        dfs(grid, vis, r - 1, c);
        dfs(grid, vis, r, c + 1);
        dfs(grid, vis, r, c - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    dfs(grid, vis, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};