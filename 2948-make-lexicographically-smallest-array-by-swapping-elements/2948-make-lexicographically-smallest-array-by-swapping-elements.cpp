class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int,int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        vector<int> ans = nums;

        int l = 0;

        while (l < n) {
            int r = l;

            while (r + 1 < n && v[r + 1].first - v[r].first <= limit) {
                r++;
            }

            vector<int> indices;

            for (int i = l; i <= r; i++) {
                indices.push_back(v[i].second);
            }

            sort(indices.begin(), indices.end());

            for (int i = 0; i < indices.size(); i++) {
                ans[indices[i]] = v[l + i].first;
            }

            l = r + 1;
        }

        return ans;
    }
};