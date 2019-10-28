class Solution:
    # 动态规划，使用一个数组来表示s[i:j]是否在wordDict上。
    def wordBreak(self, s: str, wordDict):
        dp = [0 for i in range(len(s) + 1)] 
        for i in range(len(s)):
            for j in range(i + 1, len(s) + 1):
                if i > 0 and dp[i] != 1:
                    break
                if s[i:j] in wordDict:
                    dp[j] = 1
        if dp[len(s)]:
            return True
        return False 
