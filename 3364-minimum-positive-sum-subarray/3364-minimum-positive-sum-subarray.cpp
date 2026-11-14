class Solution {
public:
    int helpy(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        if (sum > 0)
            mini = min(mini, sum);
        int i = k;
        while (i < nums.size()) {
            sum = sum - nums[i - k] + nums[i];
            if (sum > 0)
                mini = min(mini, sum);
            i++;
        }
        return mini;
    }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for (int i = l; i <= r; i++) {
            ans = min(ans, helpy(nums, i));
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};