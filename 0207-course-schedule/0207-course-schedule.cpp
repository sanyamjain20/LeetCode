class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> id(n, 0);
        queue<int> q;
        int cnt=0;
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
            cnt++;
            for (int& e : adj[x]) {
                id[e]--;
                if (id[e] == 0)
                    q.push(e);
            }
        }
        return cnt==n?true:false;
    }
};