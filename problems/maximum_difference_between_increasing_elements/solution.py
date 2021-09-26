class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        m = -1
        mi = nums[0]
        n = len(nums)
        for i in range(n):
            mi = min(mi, nums[i])
            m = max(m, nums[i] - mi)
        return m if m>0 else -1