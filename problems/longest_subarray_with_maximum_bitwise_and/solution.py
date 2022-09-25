# and with other elements will decrease it eventually

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        m = max(nums)
        ans = 1
        c = 0
        n = len(nums)
        for i in range(n):
            if nums[i]==m:
                c+=1
            else:
                ans = max(ans, c)
                c = 0
        ans = max(ans, c)
        return ans