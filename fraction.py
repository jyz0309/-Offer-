class Solution:
    def fraction(self, cont: List[int]) -> List[int]:
        def helper(x1,y1,x2,y2):
            # 第一项分子，第二项分母
            return x1*y2+x2*y1,x1*x2
        if len(cont)==1:
            return [cont[0],1]
        y1 = cont[-2]
        x2 = cont[-1]
        y,x = helper(1,y1,x2,1)
        if len(cont)==2:
            return [y,x]
        i = len(cont)-3
        while i!=-1:
            y,x = helper(1,cont[i],y,x)
            i -= 1
        return [y,x]
        
            
