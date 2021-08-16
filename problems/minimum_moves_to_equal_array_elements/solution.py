'''
Visualize the nums array as a bar graph where the value at each index is a bar of height nums[i]. Sort the array such that the bar at index 0 is minimum height and the bar at index N-1 is highest.
Now in the first iteration, make a sequence of moves such that the height at index 0 is equal to height at index N-1. Clearly this takes nums[N-1]-nums[0] moves. After these moves, index N-2 will be the highest and index 0 will still be the minimum and nums[0] will be same as nums[N-1].
In the next iteration, lets do nums[N-2]-nums[0] moves. After this iteration, nums[0], nums[N-2], and nums[N-1] will be the same.
'''

class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        c = 0
        for i in range(len(nums)-1, -1, -1):
            if nums[i] == nums[0]:
                break
            c += nums[i] - nums[0]
        return c

