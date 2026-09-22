class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++) cnt[i] = 0;
        }
    };

    int n, k;
    vector<Node> seg;

    Node merge(const Node& a, const Node& b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        for (int r = 0; r < k; r++)
            res.cnt[r] = a.cnt[r];

        for (int r = 0; r < k; r++) {
            int nr = (a.prod * r) % k;
            res.cnt[nr] += b.cnt[r];
        }

        return res;
    }

    void build(int p, int l, int r, vector<int>& nums) {
        if (l == r) {
            int x = nums[l] % k;
            seg[p].prod = x;
            seg[p].cnt[x] = 1;
            return;
        }

        int m = (l + r) / 2;

        build(p * 2, l, m, nums);
        build(p * 2 + 1, m + 1, r, nums);

        seg[p] = merge(seg[p * 2], seg[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            val %= k;

            seg[p].prod = val;

            for (int i = 0; i < k; i++)
                seg[p].cnt[i] = 0;

            seg[p].cnt[val] = 1;
            return;
        }

        int m = (l + r) / 2;

        if (idx <= m)
            update(p * 2, l, m, idx, val);
        else
            update(p * 2 + 1, m + 1, r, idx, val);

        seg[p] = merge(seg[p * 2], seg[p * 2 + 1]);
    }

    void query(int p, int l, int r, int ql, Node& cur) {
        if (r < ql)
            return;

        if (ql <= l) {
            cur = merge(cur, seg[p]);
            return;
        }

        int m = (l + r) / 2;

        query(p * 2, l, m, ql, cur);
        query(p * 2 + 1, m + 1, r, ql, cur);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->n = nums.size();
        this->k = k;

        seg.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            Node cur;
            cur.prod = 1;

            query(1, 0, n - 1, start, cur);

            ans.push_back(cur.cnt[x]);
        }

        return ans;
    }
};