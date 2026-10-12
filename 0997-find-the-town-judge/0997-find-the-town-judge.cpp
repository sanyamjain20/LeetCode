class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1&&trust.size()==0)return 1;
        unordered_map<int,int>mp;
        unordered_map<int,int>cnt;
        int ans=-1;
        for(auto &arr:trust){
            mp[arr[1]]++;
            cnt[arr[0]]++;
        }
        for(auto &x:mp){
            if(x.second==n-1)ans=x.first;
        }
        if(cnt[ans])return -1;
        return ans;
    }
};