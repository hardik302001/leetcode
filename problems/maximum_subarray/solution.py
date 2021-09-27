#courtesy codencode kadane algo



class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        
#         for i in range(1,len(nums)):
#             nums[i] = max(nums[i], nums[i-1] + nums[i])
#         return max(nums)
    
    
        
        for i in range(1,len(nums)):
            nums[i] = max(nums[i-1], 0) + nums[i]  #to consider a subarray  ending at index i, we need to add nums[i], what extra we have is nums[i-1]( that is a bonus), if it is negative we dont consider it, else we consider it
        return max(nums)