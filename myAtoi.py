class Solution:
    def myAtoi(self, str: str) -> int:
        str = str.lstrip()#去掉左边的空格
        if len(str) == 0:
            return 0
        flag = 2 if str[0] == '+' or str[0]=='-'else 1 # 判断能否直接开始
        result = 0
        for i in range(flag,len(str)+1):
            try:
                result = int(str[:i])
            except:
                break
        if result<-2147483648 :
            return -2147483648
        if result>2147483647:
            return 2147483647
        return result
