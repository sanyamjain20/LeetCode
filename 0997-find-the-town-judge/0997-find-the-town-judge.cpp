class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>s(n+1,0);
        for(auto &arr:trust){
            s[arr[1]]++;
            s[arr[0]]--;
        }
        for(int i =1;i<=n;i++){
            if(s[i]==n-1)return i;
        }
        return -1;
    }
};