class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort() 
        if len(nums) <= nums[0]: return len(nums) # edge case 
        
        for i in range(1, len(nums)): 
            if nums[i-1] < len(nums)-i <= nums[i]: return len(nums)-i
        return -1