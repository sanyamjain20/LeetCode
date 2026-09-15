class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<pair<int, int>> intervals;

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j] && (len <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;

                    if (len >= k)
                        intervals.push_back({i, j});
                }
            }
        }

        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        int ans = 0;
        int lastEnd = -1;

        for (auto &[start, end] : intervals) {
            if (start > lastEnd) {
                ans++;
                lastEnd = end;
            }
        }

        return ans;
    }
};