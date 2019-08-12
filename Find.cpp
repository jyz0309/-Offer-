/*
题目要求：在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
解题思路：在一个矩阵中查找一个数，矩阵的列从上到下递增，行由左到右递增。只需要把指针放置于左下角，这样指针向上移动、向右移动的条件是不相同的
这样就可以通过条件判断来找到是否存在该数。
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //int x = array[0].size();
        int x = array.size()-1;
        int y = 0;
        while(x>=0&&y<array[0].size()){
            if(array[x][y]>target) x--;
            else if(array[x][y]<target) y++;
            else if(array[x][y]==target) return true;
        }
        return false;
    }
};
