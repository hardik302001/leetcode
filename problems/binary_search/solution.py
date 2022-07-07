class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l = 0
        r = n-1
        
        if(nums[l]==target): return l
        if(nums[r]==target): return r
        while l<r:
            m = l + (r-l)//2
            if nums[m]==target: return m
            
            if(nums[m]>target): r = m
            else:                l = m+1
        if nums[l]==target: return l
        else:               return -1