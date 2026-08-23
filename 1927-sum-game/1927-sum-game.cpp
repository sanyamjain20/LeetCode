class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int lq = 0, rq = 0, ls = 0, rs = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                lq++;
            else {
                ls += (num[i] - '0');
            }
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rq++;
            else {
                rs += (num[i] - '0');
            }
        }
        if ((lq + rq) % 2)
            return true;
        return ls - rs != ((rq-lq) / 2) * 9;
    }
};