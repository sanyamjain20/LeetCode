class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int m = *min_element(nums.begin(), nums.end());
        for (int& x : nums) {
            ans += x - m;
        }
        return ans;
    }
};