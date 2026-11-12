class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int len = 1;
        int l = 0, r = 1;
        int n = nums.size();

        while (r < n) {
            if (nums[r] == nums[r - 1]) {
                l = r;
                r++;
                continue;
            }

            if (nums[r] > nums[r - 1]) {
                while (r < n && nums[r] > nums[r - 1])
                    r++;

                len = max(len, r - l);
            }
            else {
                while (r < n && nums[r] < nums[r - 1])
                    r++;

                len = max(len, r - l);
            }

            l = r - 1;
        }

        return len;
    }
};