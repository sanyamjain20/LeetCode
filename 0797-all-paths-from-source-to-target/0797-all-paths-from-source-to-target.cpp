class Solution {
public:
    void p(vector<vector<int>>& graph, vector<vector<int>>& ans,
              vector<int> path, int u, int d) {
        path.push_back(u);
        if (u == d) {
            ans.push_back(path);
            return;
        }
        for(int &v:graph[u]){
            p(graph,ans,path,v,d);
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;

        p(graph, ans, path, 0, n - 1);
        return ans;
    }
};