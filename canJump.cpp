class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        return can(nums,nums.size()-2,nums.size()-1);
    }
    bool can(vector<int>& nums,int m, int n){
        if(m==0){
            if(nums[0]>=n) return true;
            else if(nums[0]<n) return false;
        }
        if(nums[m]+m>=n) 
        {
            return can(nums,m-1,m);
        }
        else return can(nums,m-1,n);
    }
};
