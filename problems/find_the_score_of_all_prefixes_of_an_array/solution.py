class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        m = nums[0]
        n = len(nums)
        ans = [0]*n
        for i in range(n):
            m =max(m , nums[i])
            ans[i] = nums[i]+m
        res = [0]*n
        res[0] = ans[0]
        for i in range(1, n):
            res[i] = res[i-1]+ans[i]
        return res