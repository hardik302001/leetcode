# extension of this : https://leetcode.com/problems/subarray-product-less-than-k/

class Solution:    
    def countSubarrays(self, nums: List[int], k: int) -> int:
        l = 0
        ans = 0
        n = len(nums)
        s = 0
        
        for r in range(n):
            s+= nums[r]
            while s*(r-l+1)>=k:
                s-=nums[l]
                l+=1
            ans += (r-l+1)
        return ans