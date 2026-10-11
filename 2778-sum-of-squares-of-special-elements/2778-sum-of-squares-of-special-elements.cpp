class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=1;i<=n;i++){
            int j=i-1;
            if(n%i==0){
                ans+=nums[j]*nums[j];
            }
        }
        return ans;
    }
};