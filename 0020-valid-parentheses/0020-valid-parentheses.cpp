class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(auto x :s){
            if(x=='('||x=='{'||x=='[') stk.push(x);
            else{
                if(stk.empty()) return false;
                if(x==')' && stk.top()!= '(') return false;
                if(x=='}' && stk.top()!= '{') return false;
                if(x==']' && stk.top()!= '[') return false;
                stk.pop();
            } 
        }
        if(!stk.empty()) return false;
        return true;
    }
};