class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        one = nums.count(1)
        if one==0:
            return 0
        n = len(nums)
        m = 100000000000
        l = 0
        c = 0
        for r in range(2*len(nums)):
            if nums[r%n]==0:
                c =c + 1
                
            if((r-l+1)==one):
                m = min(m , c)
                if nums[l%n]==0:
                    c = c - 1
                l = l + 1
        
        return m
            
        
        
        