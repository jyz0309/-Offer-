class Solution:
    '''
    解题思路：回溯算法,递归中对于列表的拼接需要注意作用域相关的问题
    '''
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        length = len(nums)
        def helper(nums,cur):
            if length == len(cur):
                result.append(cur)
                return
            else:
                for i in range(len(nums)):
                    helper(nums[:i]+nums[i+1:],cur+[nums[i]])
        helper(nums,[])
        return result
