class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        stack<int> st;
        for (char& ch : s) {
            if (ch == '(')
                st.push(ch);
            else {
                if (st.empty() || st.top() == ')')
                    ans++;
                else {
                    char t = st.top();
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            st.pop();
            ans++;
        }
        return ans;
    }
};