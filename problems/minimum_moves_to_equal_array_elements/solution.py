'''
This is a really great math question that should have been categorized as "Medium". The real trick lies in this - "Increasing n - 1 smaller elements by 1 = decreasing only the max element by 1". 
decrease 1 to reach min element,
so ans = summation(for every element to reach min)
O(n)

'''

class Solution(object):
    def minMoves(self, nums):
        m = min(nums)
        c = 0
        n = len(nums)
        for i in range(n):
            c += nums[i] - m
        return c

