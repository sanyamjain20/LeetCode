class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        queue<int>q;
        vis[0] = 1;
        int cnt = 1;
        q.push(0);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v:rooms[u]){
                if(vis[v]==0){
                    vis[v]=1;
                    q.push(v);
                    cnt++;
                }
            }
        }
        return cnt==n;
    }
};