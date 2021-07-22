class Solution(object):
    def maxProduct(self, nums):

        first, second = 0, 0
        
        for number in nums:
            
            if number > first:
                # update first largest and second largest
                first, second = number, first
                
            else:
                # update second largest
                second = max( number, second)
        
        return (first - 1) * (second - 1)