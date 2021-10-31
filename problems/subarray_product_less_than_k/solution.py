#slidimg window


class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        p = 1
        l = 0
        n = len(nums)
        ans = 0
        for r in range(n):
            p = p*nums[r]
            
            while p>=k and l<=r:
                p = p//nums[l]
                l = l +1
            ans = ans + (r-l+1)
        
        return ans