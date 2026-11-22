class Solution {
public:
    bool checkString(string s) {
        int f = 0;
        for (char& ch : s) {
            if (ch == 'b')
                f = 1;
            if (f == 1 && ch == 'a')
                return false;
        }
        return true;
    }
};