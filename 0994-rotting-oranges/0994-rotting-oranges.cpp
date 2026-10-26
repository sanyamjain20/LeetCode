class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int f = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    f++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        if(f==0)return 0;
        int sz = q.size();
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            sz--;
            if (r + 1 < n && grid[r + 1][c] == 1) {
                grid[r + 1][c] = 2;
                q.push({r+1,c});
                f--;
            }
            if (c + 1 < m && grid[r][c + 1] == 1) {
                grid[r][c + 1] = 2;
                q.push({r,c+1});
                f--;
            }
            if (r - 1 >= 0 && grid[r - 1][c] == 1) {
                grid[r - 1][c] = 2;
                q.push({r-1,c});
                f--;
            }
            if (c - 1 >= 0 && grid[r][c - 1] == 1) {
                grid[r][c - 1] = 2;
                q.push({r,c-1});
                f--;
            }
            if(sz==0){
                ans++;
                sz=q.size();
            }
        }
        if(f!=0)return -1;
        return ans;
    }
};