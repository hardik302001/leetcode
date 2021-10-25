# maxsubarraysum for arr  and
# maxsubarraysum for copy of array with dall negative elements

class Solution:
    def maxAbsoluteSum(self, arr: List[int]) -> int:
        
        def maxsubarraysum(nums):
            for i in range(1,len(nums)):
                nums[i] = max(nums[i-1], 0) + nums[i]  #to consider a subarray  ending at index i, we need to add nums[i], what extra we have is nums[i-1]( that is a bonus), if it is negative we dont consider it, else we consider it
            return max(nums)
        
        
        
        arr2 = []
        for i in arr:
            i = i*-1
            arr2.append(i)
            
        return max(maxsubarraysum(arr), maxsubarraysum(arr2))
        