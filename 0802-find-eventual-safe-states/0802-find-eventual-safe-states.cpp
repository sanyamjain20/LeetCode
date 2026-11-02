class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int u, vector<int>& vis) {
        if (vis[u] == 2)
            return true;
        vis[u] = 1;
        for (int v : graph[u]) {
            if (vis[v]==1 || !dfs(graph, v, vis))
                return false;
        }
        vis[u] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> ans;

        for (int u = 0; u < V; u++) {
            if (dfs(graph, u, vis))
                ans.push_back(u);
        }

        return ans;
    }
};