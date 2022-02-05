class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        
        if len(nums)==1:
            return 0
        
        m = max(nums)
        mi = nums.index(m)
        
        nums.sort()
        if nums[-2]*2 <= m:
            return mi
        else:
            return -1