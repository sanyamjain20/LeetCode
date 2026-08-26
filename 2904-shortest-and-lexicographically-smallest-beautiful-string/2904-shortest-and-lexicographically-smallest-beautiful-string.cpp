class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        int cnt = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {

            if (s[r] == '1')
                cnt++;

            while (cnt > k) {
                if (s[l] == '1')
                    cnt--;
                l++;
            }
            if (cnt == k) {
                while (s[l] == '0')
                    l++;
                string curr = s.substr(l, r - l + 1);
                if (ans == "" || curr.length() < ans.length() ||
                    (curr.length() == ans.length() && curr < ans))
                    ans = curr;
            }
        }
        return ans;
    }
};