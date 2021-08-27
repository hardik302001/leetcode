class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums)-1
        if len(nums)==0: return 0
        
        
        while l<r:
            m = l+(r-l)//2
            if nums[m]==target:
                return m
            elif nums[m]>target:
                r = m
            else:
                l = m+1
        
        return l+1 if nums[l]<target else l