class Solution {
public:
    vector<int> factors(int x) {
        vector<int> f;

        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                f.push_back(p);
                while (x % p == 0)
                    x /= p;
            }
        }

        if (x > 1)
            f.push_back(x);

        return f;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return n;

        unordered_map<int, int> cnt;
        int l = 0, ans = 2;

        for (int r = 0; r < n; r++) {
            vector<int> f = factors(nums[r]);

            for (int p : f)
                cnt[p]++;

            while (true) {
                bool ok = true;

                for (int p : f) {
                    if (cnt[p] > 1) {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                    break;

                vector<int> lf = factors(nums[l]);

                for (int p : lf)
                    cnt[p]--;

                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};