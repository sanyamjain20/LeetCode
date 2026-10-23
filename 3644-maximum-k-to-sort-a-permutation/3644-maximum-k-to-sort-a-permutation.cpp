class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> temp = nums;
        int ans = -1;
        int n = nums.size();

        sort(temp.begin(), temp.end());

        for (int i = 0; i < n; i++) {
            if (nums[i] != temp[i])
                ans = ans & nums[i];
        }

        return ans == -1 ? 0 : ans;
    }
};