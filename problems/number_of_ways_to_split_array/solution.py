class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        n = len(nums)
        p = [0]*(n+1)          # p[i] = sum of first i elements 
        for i in range(n):
            p[i+1] = p[i]+ nums[i]
        ans = 0
        ss = sum(nums)
        for i in range(n-1):
            s1 = p[i+1]
            s2 = ss - s1
            
            if s1>=s2:
                ans+=1
        return ans
        