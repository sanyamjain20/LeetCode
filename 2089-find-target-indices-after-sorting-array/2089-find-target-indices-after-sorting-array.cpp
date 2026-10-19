class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0;
        vector<int>ans;
        while(i<nums.size()&&nums[i]<=target){
            if(nums[i]==target)ans.push_back(i);
            i++;
        }
        return ans;
    }
};