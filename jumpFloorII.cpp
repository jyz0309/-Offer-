/*
题目要求：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
解题思路，依旧直接采用递归即可，只不过是从0开始将所有函数的返回值相加
*/
class Solution {
public:
    int jumpFloorII(int number) {
        int count = 0;
         
        if(number == 0)
            return 1;
         
        for(int i =1; i<=number;++i){
            count += jumpFloorII(number-i);
        }
         
        return count;
    }
};
