class Solution {
public:
    int countCommas(int n) {
        int digit_count=0;
        int m=n;
        while(m>0){
            m/=10;
            digit_count++;
        }
        if(digit_count<4)return 0;
        return n-999;
    }
};