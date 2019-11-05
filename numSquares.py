class Solution:
    def numSquares(self, n: int) -> int:
        result = [0 for i in range(n+1)]
        for i in range(1,n+1):
            minVal = 99999
            j = 1
            while j*j<=i:
                minVal = min(result[i-j**2], minVal)
                result[i] = minVal+1
                j += 1
        return result[-1]
