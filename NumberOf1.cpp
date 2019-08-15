/*
题目要求：输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
解题思路：用1和整数进行逐位的位运算
*/
class Solution {
public:
     int  NumberOf1(int n) {
         int index = 1;
         int number = 0;
         while(index!=0){
             if((n&index)!=0) number++;
             index = index<<1;
         }
         return number;
     }
};
