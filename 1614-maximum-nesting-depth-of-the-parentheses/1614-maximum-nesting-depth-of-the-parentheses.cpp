class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int cntmax=0;
        for(int  i =0;s[i]!='\0';i++){
            char ch = s[i];
            if(ch=='(')cnt++;
            else if(ch==')')cnt--;
            cntmax=max(cnt,cntmax);
        }
        return cntmax;
    }
};