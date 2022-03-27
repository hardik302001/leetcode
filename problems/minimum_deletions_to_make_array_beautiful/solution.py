class Solution:
    def minDeletion(self, nums: List[int]) -> int:
        c = 0
        n = len(nums)
        
        for i in range(n-1):
            if (i-c)%2==0 and nums[i]==nums[i+1]:
                c = c+1
        if (n-c)&1:
            c+=1
        return c