class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int &x:nums){
            x=abs(x);
        }
        sort(nums.rbegin(),nums.rend());
        long long ans=0;
        int mid=(n+1)/2;
        for(int i =0;i<mid;i++){
            ans+=nums[i]*nums[i];
        }
        for(int i =mid;i<n;i++){
            ans-=nums[i]*nums[i];
        }
        return ans;
    }
};