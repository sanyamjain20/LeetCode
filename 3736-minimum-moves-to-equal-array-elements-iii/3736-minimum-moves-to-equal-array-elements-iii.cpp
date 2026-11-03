class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = *max_element(nums.begin(),nums.end());
        long long  ans = 0;
        for(int &x:nums){
            ans+=m-x;
        }
        return ans;
    }
};