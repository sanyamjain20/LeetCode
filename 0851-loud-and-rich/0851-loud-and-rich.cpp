class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<int>& quiet, vector<int>& lar,
            int u) {
        if (lar[u] != -1)
            return lar[u];

        lar[u] = u;

        for (int& v : adj[u]) {
            int idx = dfs(adj, quiet, lar, v);
            if (quiet[idx] < quiet[lar[u]])
                lar[u] = idx;
        }
        return lar[u];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n, vector<int>());
        vector<int> lar(n, -1);

        for (auto& arr : richer) {
            adj[arr[1]].push_back(arr[0]);
        }

        for (int i = 0; i < n; i++) {
            lar[i] = dfs(adj, quiet, lar, i);
        }
        return lar;
    }
};