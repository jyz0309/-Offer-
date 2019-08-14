/*
题目要求：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
解题思路：简单的采用递归解题即可
*/
class Solution {
public:
    int jumpFloor(int number) {
        if(number==1) return 1;
        if(number==2) return 2;
        else return jumpFloor(number-1)+jumpFloor(number-2);
    }
};
