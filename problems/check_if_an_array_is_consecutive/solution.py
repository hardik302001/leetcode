class Solution:
    def isConsecutive(self, nums: List[int]) -> bool:
        return max(nums) - min(nums) + 1 == len(nums) == len(set(nums))