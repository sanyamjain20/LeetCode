class Solution {
public:
    bool canAliceWin(int n) {
        int k = 10;
        while (n >= k) {
            n -= k;
            k--;
        }
        return k % 2;
    }
};