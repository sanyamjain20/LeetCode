class Solution {
public:
    vector<int> answer;
    
    void dfs1(int u, vector<vector<int>>& adj, string& s,
              vector<int>& last, vector<int>& newParent) {
        
        int c = s[u] - 'a';
        int prev = last[c];
        
        if (u != 0 && last[c] != -1)
            newParent[u] = last[c];
        
        last[c] = u;
        
        for (int v : adj[u]) {
            dfs1(v, adj, s, last, newParent);
        }
        
        last[c] = prev;
    }
    
    int dfs2(int u, vector<vector<int>>& finalTree) {
        int size = 1;
        
        for (int v : finalTree[u]) {
            size += dfs2(v, finalTree);
        }
        
        answer[u] = size;
        return size;
    }
    
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        
        vector<int> newParent = parent;
        vector<int> last(26, -1);
        
        dfs1(0, adj, s, last, newParent);
        
        vector<vector<int>> finalTree(n);
        for (int i = 1; i < n; i++) {
            finalTree[newParent[i]].push_back(i);
        }
        
        answer.resize(n);
        dfs2(0, finalTree);
        
        return answer;
    }
};