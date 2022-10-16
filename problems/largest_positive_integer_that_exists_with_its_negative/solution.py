class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        s = set(nums)
        a = -1
        for i in nums:
            if i>0:
                if -1*i in s:
                    a = max(a , i)
        return a