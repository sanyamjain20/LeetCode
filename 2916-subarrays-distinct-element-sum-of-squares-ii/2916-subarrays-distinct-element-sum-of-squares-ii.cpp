class Solution {
    using ll = long long;
    static const int MOD = 1e9 + 7;

    struct Node {
        ll sum = 0, sq = 0, lazy = 0;
    };

    vector<Node> seg;
    int n;

    void apply(int idx, int l, int r, ll val) {
        ll len = r - l + 1;
        seg[idx].sq = (seg[idx].sq + 2 * val * seg[idx].sum
                       + val * val % MOD * len) % MOD;
        seg[idx].sum = (seg[idx].sum + val * len) % MOD;
        seg[idx].lazy = (seg[idx].lazy + val) % MOD;
    }

    void push(int idx, int l, int r) {
        if (seg[idx].lazy == 0 || l == r) return;
        int mid = (l + r) / 2;
        ll val = seg[idx].lazy;
        apply(idx * 2, l, mid, val);
        apply(idx * 2 + 1, mid + 1, r, val);
        seg[idx].lazy = 0;
    }

    void update(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(idx, l, r, 1);
            return;
        }
        push(idx, l, r);
        int mid = (l + r) / 2;
        update(idx * 2, l, mid, ql, qr);
        update(idx * 2 + 1, mid + 1, r, ql, qr);
        seg[idx].sum = (seg[idx * 2].sum + seg[idx * 2 + 1].sum) % MOD;
        seg[idx].sq = (seg[idx * 2].sq + seg[idx * 2 + 1].sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        vector<int> last(100001, -1);
        ll ans = 0;

        for (int r = 0; r < n; r++) {
            int p = last[nums[r]];
            update(1, 0, n - 1, p + 1, r);
            last[nums[r]] = r;
            ans = (ans + seg[1].sq) % MOD;
        }

        return ans;
    }
};