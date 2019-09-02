class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max = array[0];
        int last = array[0];
        for(int i=1;i<array.size();i++){
            if(last>=0) last = last+array[i];
            else last = array[i];
            if(max<last) max = last;
        }
        return max;
    }
};
