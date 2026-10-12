class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        int ans=0;
        vector<int>s(n+2,0);
        for(int i=0;i<n;i++){
            s[edges[i][0]]++;
            s[edges[i][1]]++;
        }
        for(int i=1;i<s.size();i++){
            if(s[i]==n)ans=i;
        }
        return ans;
    }
};