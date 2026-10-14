class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while (num > 0) {
            if (sum >= 9) {
                ans += ('0' + 9);
                sum -= 9;
                num--;
            } else {
                ans += ('0' + sum);
                sum = 0;
                num--;
            }
        }
        if(sum)return "";
        return ans;
    }
};