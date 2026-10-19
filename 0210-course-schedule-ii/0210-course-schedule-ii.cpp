class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> id(n, 0);
        queue<int> q;
        vector<int> ans;
        vector<vector<int>> adj(n);
        for (auto& x : prerequisites) {
            adj[x[1]].push_back(x[0]);
            id[x[0]]++;
        }
        for (int i = 0; i < n; i++) {
            if (id[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for (int& e : adj[x]) {
                id[e]--;
                if (id[e] == 0)
                    q.push(e);
            }
        }
        if (ans.size() == n)
            return ans;
        return {};
    }
};