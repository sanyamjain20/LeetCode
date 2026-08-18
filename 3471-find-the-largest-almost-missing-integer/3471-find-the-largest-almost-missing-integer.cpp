class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>f;
        int ans=-1;
        int mx=-1;
        for(auto &x:nums){
            f[x]++;
            mx=max(mx,x);
        }
        if(k==1){
            for(auto &x:nums){
                if(f[x]==1&&x>ans)ans=x;
            }
            return ans;
        }
        if(k==n)return mx;
        if(f[nums[0]]==1)
            if(f[nums[n-1]]!=1||nums[0]>nums[n-1])return nums[0];
        if(f[nums[n-1]]==1)return nums[n-1];
        return -1;
    }
};