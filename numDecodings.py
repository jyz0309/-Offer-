class Solution:
# 暴力递归
    result = 0
    @classmethod
    def numDecodings(self, s: str) -> int:
        if s[0] == '0':
            return 0
        for i in range(1, len(s) + 1):
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
        for i in range(1, len(s) + 1):
            if int(s[0:i]) > 26:
                continue
            else:
                self.helper(l - i, s[i:len(s)])
