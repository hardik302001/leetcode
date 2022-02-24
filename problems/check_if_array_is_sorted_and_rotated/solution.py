class Solution:
    def check(self, nums: List[int]) -> bool:
        cnt = 0
        for i in range(1, len(nums)): 
            if nums[i-1] > nums[i]: cnt += 1
        return cnt == 0 or cnt == 1 and nums[-1] <= nums[0]