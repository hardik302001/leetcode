class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        s = 0
        n = len(nums)
        for i in range(0,n,2):
            s = s + nums[i]
        return s