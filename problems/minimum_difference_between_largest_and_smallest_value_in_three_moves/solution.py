# also see: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/submissions/



# If the size <= 4, then just delete all the elements and either no or one element would be left giving the answer 0.
# else sort the array
# there are 4 possibilities now:-

# delete 3 elements from left and none from right
# delete 2 elements from left and one from right
# and so on.. now just print the minima.

# by delete we mean , update itzs value o maxima , or minima , or any vaalue between mmaxima and minima...


class Solution:
    def minDifference(self, nums: List[int]) -> int:
        
        if len(nums) <= 4: return 0
        nums.sort()
        
        return min(nums[-1] - nums[3], nums[-2] - nums[2], nums[-3] - nums[1], nums[-4] - nums[0])