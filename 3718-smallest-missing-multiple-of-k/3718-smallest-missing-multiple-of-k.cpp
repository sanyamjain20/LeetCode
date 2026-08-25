class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<int> h;
        int i;
        for (auto& x : nums)
            h.insert(x);
        for (i = 1; i <= 100; i++)
            if (h.find(k * i) == h.end())
                return i * k;
        return k*i;
    }
};