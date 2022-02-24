class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        
        s = 0
        l = 0
        m = -10000000000000
        n = len(nums)
        
        for r in range(n):
            s += nums[r]
            
            while (r-l+1)>k:
                s = s - nums[l]
                l += 1
            
            if(r-l+1)==k and s>m:
                m = s
            
            
        return m/k
                