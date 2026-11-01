class Solution {
public:

    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int ans= INT_MAX;
        for(int i =0;i<n-1;i+=2){
            if(nums[i+1]/1000>0){
                ans=min(ans,nums[i]*10000+nums[i+1]);
            }
            else if(nums[i+1]/100>0){
                ans=min(ans,nums[i]*1000+nums[i+1]);
            }
            else if(nums[i+1]/10>0){
                ans=min(ans,nums[i]*100+nums[i+1]);
            }
            else{
                ans=min(ans,nums[i]*10+nums[i+1]);
            }
        }
        return ans;
    }
};