class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        c = 0
        n = len(nums)
        for i in range(n-1, 0, -1):
            if nums[i-1]>nums[i]:
                d = (nums[i-1]+nums[i]-1)//nums[i]
                c+= d-1
                nums[i-1] = nums[i-1]//d
        return c