/*
题目描述:
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
Answer:遍历一遍数组，将偶数存入even列表中，将奇数存入odd列表中，然后进行拼接
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> even;
        vector<int> odd;
        int i;
        for(i=0;i<array.size();i++){
            if(array[i]%2==0) even.push_back(array[i]);
            else odd.push_back(array[i]);
        }
        odd.insert(odd.end(),even.begin(),even.end());
        array = odd;
    }
};
