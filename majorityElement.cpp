class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> dic;
        int l = nums.size();
        auto i = nums.begin();
        for(;i!=nums.end();i++){
            dic[*i] += 1;
            if (dic[*i]> l/2){
                return *i;
            }
        }
        return 0;
    }
};
