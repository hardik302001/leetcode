# Leveraging on the fact that all numbers are distinct in nums, we can find the largest number with enough.


# maximum in range(0 , n-k)

class Solution:
    def largestSubarray(self, nums: List[int], k: int) -> List[int]:
        n =len(nums)
        m = max(nums[:n-k+1])
        ind = nums.index(m)
        return nums[ind:ind+k]
    
    
# ------------------------------------------------------------------------
    
    
#  follow up : https://leetcode.com/problems/last-substring-in-lexicographical-order/