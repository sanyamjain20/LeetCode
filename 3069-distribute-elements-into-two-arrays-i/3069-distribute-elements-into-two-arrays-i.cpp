class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        vector<int> b;
        int k = 0;
        a.push_back(nums[k++]);
        b.push_back(nums[k++]);
        int i = 0, j = 0;
        int la = a[0], lb = b[0];
        while (k < n) {
            if (la > lb) {
                a.push_back(nums[k++]);
                la = a[++i];
            } else {
                b.push_back(nums[k++]);
                lb = b[++j];
            }
        }
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
};