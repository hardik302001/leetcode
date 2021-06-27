class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        nums.sort()
        ans = -(nums[0]*nums[1])
        ans = ans + (nums[-1]*nums[-2])
        return ans