class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int>suffix(n+1,0);
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        int newM;
        for(int i =n-1;i>=0;i--){
            suffix[i]=suffix[i+1]+piles[i];
        }
        for(int i =n-1;i>=0;i--){
            for(int M= n;M>=1;M--){
                if(2*M>=n-i){
                    dp[i][M]=suffix[i];
                    continue;
                }
                for(int X=1;X<=2*M;X++){
                    newM=max(M,X);
                    dp[i][M]=max(dp[i][M],suffix[i]-dp[i+X][newM]);
                }
            }
        }
        return dp[0][1];
    }
};