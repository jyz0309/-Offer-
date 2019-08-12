/*
题目要求：大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项(从0开始，第0项为0)。(n<=39)
解题思路：直接通过for循环进行求解
*/
class Solution {
public:
    int Fibonacci(int n) {
        int result = n;
        int first = 0;
        int second = 1;
        for(int i=2;i<=n;i++){
            result = first+second;
            first = second;
            second = result;
        }
        return result;
    }
};
