'''
暴力递归不可取
class Solution:
    result = 0
    @classmethod
    def numDecodings(self, s: str) -> int:
        if s[0] == '0':
            return 0
        if len(s) >= 3:
            j = 3
        else:
            j = len(s)+1
        for i in range(1, j):
            if int(s[0:i]) > 26:
                continue
            else:
                self.helper(len(s) - i, s[i:len(s)])
        return self.result
    
    @classmethod
    def helper(self, l, s):
        if s != "" and s[0] == '0':
            return
        if l == 0:
            self.result += 1
            return
        if len(s) >= 3:
            j = 3
        else:
            j = len(s)+1
        for i in range(1, j):
            if int(s[0:i]) > 26:
                continue
            else:
                self.helper(l - i, s[i:len(s)])
'''


class Solution:
    @classmethod
    def numDecodings(self, s):
        result = [0 for _ in range(len(s))]
        if len(s) == 0 or len(s) == 1:
            return "" if len(s) == 0 else 1
        result[0] = 1
        if int(s[0])*10+int(s[1])>26:
            result[1] = 1
        else:
            result[1] = 2
        for i in range(2, len(s)):
            if 10*int(s[i-1])+int(s[i]) <= 26:
                result[i] = result[i-1]+result[i-2]
            else:
                result[i] = result[i-1]
        return result[-1]


result = Solution.numDecodings("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948")
print(result )
