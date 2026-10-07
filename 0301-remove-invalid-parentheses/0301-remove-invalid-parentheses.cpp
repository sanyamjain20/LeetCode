class Solution {
public:
    void solve(string& s, int i, int b, int l, int r, string temp,
               set<string>& ans) {
        if (i == s.size()) {
            if (b == 0 && l == 0 && r == 0) {
                ans.insert(temp);
            }
            return;
        }
        if (s[i] == '(') {
            if (l > 0)
                solve(s, i + 1, b, l - 1, r, temp, ans);

            solve(s, i + 1, b + 1, l, r, temp + s[i], ans);
        } else if (s[i] == ')') {
            if (r > 0)
                solve(s, i + 1, b, l, r - 1, temp, ans);
            if (b > 0)
                solve(s, i + 1, b - 1, l, r, temp + s[i], ans);
        } else
            solve(s, i + 1, b, l, r, temp + s[i], ans);
    }
    vector<string> removeInvalidParentheses(string s) {
        int b = 0, r = 0, l = 0;
        for (char& c : s) {
            if (c == '(')
                b++;
            else if (c == ')') {
                if (b == 0)
                    r++;
                else
                    b--;
            }
        }
        l = b;
        set<string> ans;
        string temp = "";
        solve(s, 0, 0, l, r, temp, ans);
        if (ans.size() == 0)
            return {""};
        vector<string> res(ans.begin(), ans.end());
        return res;
    }
};