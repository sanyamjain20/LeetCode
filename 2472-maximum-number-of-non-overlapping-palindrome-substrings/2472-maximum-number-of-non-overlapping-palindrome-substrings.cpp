class Solution {
public:
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i <= n - k; i++) {
            if (isPalindrome(s, i, i + k - 1)) {
                count++;
                i += k - 1;
            } else if (i + k < n && isPalindrome(s, i, i + k)) {
                count++;
                i += k;
            }
        }
        return count;
    }
};