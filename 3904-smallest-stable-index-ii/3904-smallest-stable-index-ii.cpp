class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxa(n);
        vector<int> mini(n);
        int ma = nums[0];
        int mi = nums[n - 1];

        for (int i = 0; i < n; i++) {
            if (nums[i] >= ma) {
                maxa[i] = nums[i];
                ma = nums[i];
            } else
                maxa[i] = ma;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] <= mi) {
                mini[i] = nums[i];
                mi = nums[i];
            } else
                mini[i] = mi;
        }

        for (int i = 0; i < n; i++) {
            if (maxa[i] - mini[i] <= k) {
               return i;
            }
        }
        return -1;
    }
};