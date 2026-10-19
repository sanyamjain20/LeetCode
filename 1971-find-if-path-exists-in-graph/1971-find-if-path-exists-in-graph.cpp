class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<bool> v(n, false);
        queue<int> q;
        vector<vector<int>> adj(n);
        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        q.push(source);
        v[source]=true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (x == destination)
                return true;
            for (int& i : adj[x]) {
                if (!v[i]) {
                    q.push(i);
                    v[i] = true;
                }
            }
        }
        return false;
    }
};