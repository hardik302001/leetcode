class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        ans = -1
        n = len(nums)
        for i in range(n):
            if sum(nums[:i])==sum(nums[i+1:]):
                ans = i
                break
        return ans