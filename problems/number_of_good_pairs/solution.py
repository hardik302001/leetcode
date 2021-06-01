class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        d = {}
        m = len(nums)
        for i in nums:
            if i in d:d[i]+=1
            else:d[i] = 1
        c = 0
        for i in d:
            c = c + d[i]*(d[i]-1)//2
        return c