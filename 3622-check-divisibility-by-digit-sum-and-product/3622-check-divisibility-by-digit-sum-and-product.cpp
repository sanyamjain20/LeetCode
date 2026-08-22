class Solution {
public:
    bool checkDivisibility(int n) {
        int m = n ;
        int r=0;
        int s=0,p=1;
        while(m>0){
            r=m%10;
            m/=10;
            s+=r;
            p*=r;
        }
        return n%(s+p)==0;
    }
};