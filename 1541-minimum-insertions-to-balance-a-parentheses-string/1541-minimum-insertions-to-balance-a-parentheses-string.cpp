class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int cnt=0;
        int i = 0;
        while (s[i] != '\0') {
            if (s[i] == '(')
                cnt++;
            else {
                if (cnt==0) {
                    ans++;
                    cnt++;
                }
                if (s[i + 1] == ')') {
                    cnt--;
                    i++;
                } else{
                    ans++;
                    cnt--;
                }
            }
            i++;
        }
        ans+=2*cnt;
        return ans;
    }
};