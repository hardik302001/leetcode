#O(n^2)
'''
class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:

        def strictly_increasing(nums):
            for i in range(1, len(nums)):
                if nums[i - 1] >= nums[i]:
                    return False

            return True

        for i in range(len(nums)):
            if strictly_increasing(nums[:i] + nums[i + 1:]):
                return True

        return False
'''


class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:
        n = len(nums)
        c = 0
        for i in range(1, n):
            if nums[i]<=nums[i-1]:
                if c>=1:
                    return False
                
                if i>=2:
                    if nums[i-2]<nums[i]:
                        nums[i-1] = nums[i]
                    else:
                        nums[i] = nums[i-1]
                elif i ==1:
                    nums[i-1] = nums[i]
                c = c + 1
            # print(nums)
        return True