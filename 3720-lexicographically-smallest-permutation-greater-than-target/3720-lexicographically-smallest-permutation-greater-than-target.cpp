class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> f(26, 0);

        for (char ch : s)
            f[ch - 'a']++;

        string ans;

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            if (f[x] > 0) {
                ans += target[i];
                f[x]--;
            } else {
                int j = x + 1;

                while (j < 26 && f[j] == 0)
                    j++;

                if (j < 26) {
                    ans += char('a' + j);
                    f[j]--;

                    for (int k = 0; k < 26; k++)
                        ans += string(f[k], char('a' + k));

                    return ans;
                }

                for (int k = i - 1; k >= 0; k--) {
                    f[target[k] - 'a']++;

                    int y = target[k] - 'a';
                    int j = y + 1;

                    while (j < 26 && f[j] == 0)
                        j++;

                    if (j < 26) {
                        string res = target.substr(0, k);
                        res += char('a' + j);
                        f[j]--;

                        for (int c = 0; c < 26; c++)
                            res += string(f[c], char('a' + c));

                        return res;
                    }
                }

                return "";
            }
        }

        // target itself is a permutation of s.
        // Backtrack from the last position.
        for (int i = n - 1; i >= 0; i--) {
            f[target[i] - 'a']++;

            int x = target[i] - 'a';
            int j = x + 1;

            while (j < 26 && f[j] == 0)
                j++;

            if (j < 26) {
                string res = target.substr(0, i);
                res += char('a' + j);
                f[j]--;

                for (int k = 0; k < 26; k++)
                    res += string(f[k], char('a' + k));

                return res;
            }
        }

        return "";
    }
};