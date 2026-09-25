class Solution {
public:
    set<string> combine(set<string>& a, set<string>& b) {
        set<string> res;
        for (string x : a) {
            for (string y : b) {
                res.insert(x + y);
            }
        }
        return res;
    }
    set<string> parseExpr(string& s, int& i) {
        set<string> res = parseTerm(s, i);
        while (i < s.size() && s[i] == ',') {
            i++;
            set<string> next = parseTerm(s, i);
            res.insert(next.begin(), next.end());
        }
        return res;
    }
    set<string> parseTerm(string& s, int& i) {
        set<string> res;
        res.insert("");
        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur;
            if (s[i] == '{') {
                i++;
                cur = parseExpr(s, i);
                i++;
            } else {
                cur.insert(string(1, s[i]));
                i++;
            }
            res = combine(res, cur);
        }
        return res;
    }
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = parseExpr(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};