class Solution {
public:
    int helper(vector<vector<int>>& grid,vector<vector<int>>& vis,int r , int c){
        int n =grid.size();
        int m = grid[0].size();
        
        if(r<0||r==n||c<0||c==m)return 1;
        if(grid[r][c]==0)return 1;
        if(vis[r][c])return 0;
        vis[r][c]=1;
        return helper(grid,vis,r-1,c)+helper(grid,vis,r+1,c)+helper(grid,vis,r,c-1)+helper(grid,vis,r,c+1);

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int ans =0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&!vis[i][j]){
                    ans+=helper(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};