class Solution {
public:
    void ReverseWord(string &str, int s, int e)
    {
        while(s < e)
            swap(str[s++], str[e--]);
    }
 
    string ReverseSentence(string str) {
        ReverseWord(str, 0, str.size() - 1); //先整体翻转
        int s = 0;
        int i = 0;
        while(i < str.size())
        {
            while(i < str.size() && str[i] == ' ') //空格跳过
                i++;
            s = i; //记录单词的第一个字符的位置
            while(i < str.size() && str[i] != ' ') //不是空格 找单词最后一个字符的位置
            {
                i++;
            }
            ReverseWord(str, s, i - 1); //局部翻转
        }
        return str;
    }

};
