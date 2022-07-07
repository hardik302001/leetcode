class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        n = len(nums)
        need = sum(nums)-x
        
        if need<0: return -1
        elif need == 0: return n
        
        l = 0
        ans = -1
        s = 0
        for r in range(n):
            s+= nums[r]
            while s>need:
                s-=nums[l]
                l+=1
            if s==need:
                ans = max(ans , r-l+1)
        
        if ans==-1: return -1
        else:       return (n-ans)