class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        stack<char> st;
        int i = 0;
        while (s[i] != '\0') {
            if (s[i] == '(')
                st.push(s[i]);
            else {
                if (st.empty()) {
                    ans++;
                    st.push('(');
                }
                if (s[i + 1] == ')') {
                    st.pop();
                    i++;
                } else{
                    ans++;
                    st.pop();
                }
            }
            i++;
        }
        while (!st.empty()) {
            st.pop();
            ans += 2;
        }
        return ans;
    }
};