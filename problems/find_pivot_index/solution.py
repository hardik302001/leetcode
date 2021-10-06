class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        totSum = sum(nums)
        tempSum = 0
        for i in range(len(nums)):
            if(nums[i] == totSum - 2*tempSum): return i
            tempSum += nums[i]
        return -1