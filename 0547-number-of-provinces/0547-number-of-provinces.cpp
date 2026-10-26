class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& vis, int u) {
        vis[u] = 1;
        for (int v = 0; v < isConnected.size(); v++) {
            if (isConnected[u][v] == 1 && vis[v] != 1)
                dfs(isConnected, vis, v);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<int> vis(n, 0);
        for (int u = 0; u < n; u++) {
            if (vis[u] == 0) {
                dfs(isConnected, vis, u);
                ans++;
            }
        }
        return ans;
    }
};