class Solution:
    # 本质上其实是一个排序，排序的对比规则是由自己定义的规则
    def largestNumber(self, nums: List[int]) -> str:
        if sum(nums) == 0:
            return "0"
        result = [nums[0]]
        for i in range(1,len(nums)):
            for j in range(len(result)):
                cur = self.compare(nums[i],result[j])
                if cur == nums[i]:
                    result.insert(j, nums[i])
                    break
                elif j == len(result)-1:
                    result.append(nums[i])
                else:
                    continue
        res = ""
        for i in range(len(result)):
            res += str(result[i])
        return res
                
    def compare(self, num1, num2):
        num_1 = str(num1)+str(num2)
        num_2 = str(num2)+str(num1)
        if int(num_1)>int(num_2):
            return num1
        else:
            return num2
