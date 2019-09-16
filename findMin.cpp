class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1||nums[0]<nums.back()) return nums[0];
        int left = 0;
        int right = nums.size()-1;
        while(right>left){
            int mid = (right+left)/2;
            if(nums[mid]>=nums[0]){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return nums[right];
    }
};
