class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0,j=1,z=nums.size()-1;
        int min = 99999;
        int sum = 0;
        int min_sum=0;
        while(i!=nums.size()-2){
            sum = nums[i]+nums[j]+nums[z];
            if(abs(target-nums[i]-nums[j]-nums[z])<min){
                min_sum = nums[i]+nums[j]+nums[z];
                min = abs(target-min_sum);
            }
            if(sum>target) z--;
            if(sum<target) j++;
            if(sum==target) return target;
            if(z==j){
                i++;
                j=i+1;
                z=nums.size()-1;
            }
        }
        return min_sum;
    }
};
