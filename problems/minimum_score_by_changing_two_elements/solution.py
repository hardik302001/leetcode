'''
Intuition
We see that we have to sort the array to easily find low score and high score

Approach
After sorting the array, we have 3 ways to optimize this problem:

. Increase nums[0], nums[1] equal to nums[2], now low=0, high=nums[n-1]-nums[2]
. Reduce nums[n-1], nums[n-2] equal to nums[n-3], now low=0, high=nums[n-3]-nums[0]
. Increase nums[0] equal to nums[1], nums[n-1] equal to nums[n-2], now low=0, high=nums[n-2]-nums[1]

'''


class Solution:
    def minimizeSum(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        res = 10**12
        
        return min(nums[-1]-nums[2] , nums[-3]-nums[0] , nums[-2]-nums[1])
            