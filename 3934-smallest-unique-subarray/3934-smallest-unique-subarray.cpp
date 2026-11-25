class Solution {
public:
    vector<int> buildSuffixArray(vector<int>& a) {
        int n = a.size();
        vector<int> sa(n), rnk(n), tmp(n);

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rnk[i] = a[i];
        }

        for (int k = 1; k < n; k *= 2) {
            sort(sa.begin(), sa.end(), [&](int i, int j) {
                if (rnk[i] != rnk[j])
                    return rnk[i] < rnk[j];

                int ri = i + k < n ? rnk[i + k] : -1;
                int rj = j + k < n ? rnk[j + k] : -1;

                return ri < rj;
            });

            tmp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int x = sa[i - 1];
                int y = sa[i];

                bool different = rnk[x] != rnk[y];

                int rx = x + k < n ? rnk[x + k] : -1;
                int ry = y + k < n ? rnk[y + k] : -1;

                if (rx != ry)
                    different = true;

                tmp[y] = tmp[x] + different;
            }

            rnk = tmp;

            if (rnk[sa[n - 1]] == n - 1)
                break;
        }

        return sa;
    }

    vector<int> buildLCP(vector<int>& a, vector<int>& sa) {
        int n = a.size();
        vector<int> rank(n), lcp(n);

        for (int i = 0; i < n; i++)
            rank[sa[i]] = i;

        int k = 0;

        for (int i = 0; i < n; i++) {
            if (rank[i] == 0)
                continue;

            int j = sa[rank[i] - 1];

            while (i + k < n && j + k < n && a[i + k] == a[j + k]) {
                k++;
            }

            lcp[rank[i]] = k;

            if (k)
                k--;
        }

        return lcp;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 1;

        vector<int> sa = buildSuffixArray(nums);
        vector<int> lcp = buildLCP(nums, sa);

        int ans = n;

        for (int i = 0; i < n; i++) {
            int left = (i == 0 ? 0 : lcp[i]);
            int right = (i == n - 1 ? 0 : lcp[i + 1]);

            int need = max(left, right) + 1;

            int suffixLength = n - sa[i];

            if (need <= suffixLength)
                ans = min(ans, need);
        }

        return ans;
    }
};