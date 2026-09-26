class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int i = 0;
        string ans = "";
        unordered_map<string, string> h;
        for (auto& l : knowledge) {
            h[l[0]] = l[1];
        }
        while (s[i] != '\0') {
            if (s[i] != '(') {
                ans += s[i];
                i++;
            } else {
                i++;
                string key = "";
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }
                i++;
                if (h.count(key))
                    ans += h[key];
                else
                    ans += '?';
            }
        }
        return ans;
    }
};