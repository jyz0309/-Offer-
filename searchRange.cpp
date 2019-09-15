class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        if(left==right){
            if(nums[0]==target) return {0,0};
            else return {-1,-1};
        }
        vector<int> result{-1,-1};
        while(right>=left){
            int mid = (right+left)/2;
            if(nums[mid]>target) right = mid-1;
            else if(nums[mid]<target) left = mid+1;
            else if(nums[mid]==target){
                int begin = mid;
                int end = mid;
                while((begin!=-1||end!=nums.size())){
                    if((begin!=-1&&end!=nums.size())&&nums[begin]!=target&&nums[end]!=target){break;}
                    if(begin!=-1&&end==nums.size()&&nums[begin]!=target){break;}
                    if(begin==-1&&end!=nums.size()&&nums[end]!=target){break;}
                    if(begin!=-1&&nums[begin]==target){begin--;}
                    if(end!=nums.size()&&nums[end]==target){end++;}
                }
                result[0] = begin+1;
                result[1] = end-1;
                break;
            }
        }
        return result;
    }
};
