class Solution {
public:
    long long dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int r,
             int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
            return 0;

        if (grid[r][c] == 0 || visited[r][c])
            return 0;
        visited[r][c] = 1;
        
        return (long long)grid[r][c] + dfs(grid, visited, r - 1, c) +
               dfs(grid, visited, r + 1, c) + dfs(grid, visited, r, c - 1) +
               dfs(grid, visited, r, c + 1);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    if (dfs(grid, visited, i, j)%k==0)
                        ans++;
                }
            }
        }

        return ans;
    }
};
