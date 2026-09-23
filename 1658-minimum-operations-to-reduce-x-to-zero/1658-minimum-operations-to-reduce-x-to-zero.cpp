class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int k = sum - x;
        if (k < 0)
            return -1;
        int l = 0;
        int s = 0;
        int len = -1;
        
        for (int r = 0; r < n; r++) {
            s += nums[r];

            while (l <= r && s > k) {
                s -= nums[l];
                l++;
            }

            if (s == k)
                len = max(len, r - l + 1);
        }

        return len == -1 ? -1 : n - len;
    }
};