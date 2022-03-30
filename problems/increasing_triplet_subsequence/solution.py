# O(n) 3 pass and extra space
'''
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        n = len(nums)
        mi = [1000000000000]*n            # min of nums[:i+1]   min from bginning to ith position
        ma = [-1000000000000]*n           # max of nums[i:]   : max from ith poition to end
        
        mi[0] = nums[0]
        ma[-1] = nums[-1]
        
        for i in range(1, n):
            mi[i] = min(nums[i] , mi[i-1])
        for i in range(n-2 , -1 , -1):
            ma[i] = max(nums[i] , ma[i+1])
        
        for i in range(1 , n-1):
            if mi[i-1] < nums[i] < ma[i+1]:
                return True
        return False
            
'''

# O(n), one pass and no xtra space
# Start with the maximum numbers for the first and second element. Then:
# (1) Find the first smallest number in the 3 subsequence
# (2) Find the second one greater than the first element, reset the first one if it's smaller

class Solution:
    def increasingTriplet(self, nums):
        first = second = float('inf')
        for n in nums:
            if n <= first:
                first = n
            elif n <= second:
                second = n
            else:
                return True
        return False