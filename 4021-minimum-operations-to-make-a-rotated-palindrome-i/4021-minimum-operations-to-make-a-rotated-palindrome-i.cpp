class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int ans=INT_MAX;
        for(int k =0;k<n;k++){
            int cost=0;
            for(int i=0;i<n/2;i++){
                char c1 = s[(i+k)%n];
                char c2 = s[(n-1-i+k)%n];
                int x = abs(c2-c1);
                cost  +=min(x,26-x);
            }
            ans=min(ans,k+cost);
        }
        return ans;
    }
};