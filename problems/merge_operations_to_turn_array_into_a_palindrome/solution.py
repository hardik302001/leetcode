class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        
        left = 0
        right = len(nums)-1
        count = 0
        
        while left <= right:
            if nums[left] != nums[right]:
                
                if nums[left] < nums[right]:
                    nums[left+1] += nums[left]
                    left += 1
                else:
                    nums[right-1] += nums[right]
                    right -= 1
                    
                count += 1
                
            else:            
                left += 1
                right -= 1
            
        return count