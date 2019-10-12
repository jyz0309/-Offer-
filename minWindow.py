from collections import Counter 

class Solution(object):
    def minWindow(self, s, t):
        if not t or not s:
            return ""
        dic_t = Counter(t)
        word = {}
        l,r=0,0
        length = len(dic_t)
        form = 0
        ans = [99999,0,0]
        while r<len(s):
            word[s[r]] = word.get(s[r],0)+1
            if s[r] in dic_t and word[s[r]] == dic_t[s[r]]:
                form += 1
            while r>=l and form == length:
                if r-l+1 < ans[0]:
                    ans = [r-l+1,l,r]
                word[s[l]] -= 1
                if s[l] in dic_t and word[s[l]] < dic_t[s[l]]:
                    form -=1
                l+=1
            r+=1
        return "" if ans[0] == 99999 else s[ans[1]:ans[2]+1]
