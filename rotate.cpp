class Solution {
// 旋转数组C++实现，首先将数组分为两个部分，即将被旋转的部分以及其余的不用从后调到前面的部分，分别将两个部分进行逆序，然后整体进行逆序，复杂度为O(1)
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        reverse1(nums,0,nums.size()-k-1);
        reverse1(nums,nums.size()-k,nums.size()-1);
        reverse1(nums,0,nums.size()-1);
    }
    void reverse1(vector<int>& a,int s,int e)
    {
        while(s<e)
        {
            int temp=a[e];
            a[e]=a[s];
            a[s]=temp;
            e--;
            s++;
        }
    }
};
