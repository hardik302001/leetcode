class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        
        n = len(nums)
        p = [0]*(n+1)
        for i in range(n):
            p[i+1] = nums[i] + p[i]
        m = min(p)
        if m<0:
            return (1 + -1*m)
        else:
            return 1