class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> l;

        for (char c : s) {
            if (c != ')') {
                l.push(c);
            } else {
                string temp = "";

                while (l.top() != '(') {
                    temp += l.top();
                    l.pop();
                }

                l.pop();

                for (char x : temp) {
                    l.push(x);
                }
            }
        }

        string ans = "";

        while (!l.empty()) {
            ans += l.top();
            l.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};