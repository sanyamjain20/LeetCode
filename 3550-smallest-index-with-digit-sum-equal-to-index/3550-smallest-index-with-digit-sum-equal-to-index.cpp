class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int s;
        for(int i = 0;i<nums.size();i++){
            s=0;
            while(nums[i]>0){
                s+=nums[i]%10;
                nums[i]/=10;
            }
            if(s==i)return i;
        }
        return -1;
    }
};