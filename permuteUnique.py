class Solution:
    '''
    Leetcode 47 全排列II
    解题思路：和全排列差不多，通过使用字典来达到剪枝的效果
    '''
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        length = len(nums)
        cur = []
        result = []
        dic = {}
        for i in range(len(nums)+1):
            dic[i] = []
        def helper(nums,cur):
            if len(cur)!=0 and cur not in dic[len(cur)]:
                dic[len(cur)].append(cur)
            elif len(cur)!=0 and cur in dic[len(cur)]:
                return 
            if len(cur) == length:
                result.append(cur)
                return
            elif len(cur) != length:
                for i in range(len(nums)):
                    helper(nums[:i]+nums[i+1:],cur+[nums[i]])
        helper(nums,cur)
        return result
