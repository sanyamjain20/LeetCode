
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<int> d(n);

        for (int i = 0; i < n; i++) {
            d[i] = abs(nums1[i] - nums2[i]);
        }

        sort(d.rbegin(), d.rend());

        if (k >= accumulate(d.begin(), d.end(), 0LL)) return 0;

        d.push_back(0);

        for (int i = 0; i < n; i++) {
            long long need = 1LL * (d[i] - d[i + 1]) * (i + 1);

            if (need <= k) {
                k -= need;
            } else {
                long long level = k / (i + 1);
                int rem = k % (i + 1);

                for (int j = 0; j <= i; j++) {
                    d[j] = d[i] - level - (j < rem);
                }

                k = 0;
                break;
            }
        }

        long long ans = 0;
        for (int x : d) {
            ans += 1LL * x * x;
        }

        return ans;
    }
};
