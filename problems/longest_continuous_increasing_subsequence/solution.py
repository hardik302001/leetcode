class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        c = 1
        m = 1
        n = len(nums)
        
        for i in range(1,n):
            if nums[i-1] < nums[i]:
                c = c +1
            else:c =1
            m = max(m,c)
        return m