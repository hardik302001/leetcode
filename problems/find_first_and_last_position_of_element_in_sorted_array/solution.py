class Solution(object): 

#### Main function

    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result = [-1, -1] #1
        
        result[0] = self.findStartingIndex(nums, target)  #2 
        result[1] = self.findEndingIndex(nums, target)  #3
        
        return result #4
		
#### Helper function 1 

    def findStartingIndex(self, nums, target):
        index = -1 #5 
        low, high = 0, len(nums) -1 #6
        
        while low <= high: #7
            mid = low + (high - low)//2 #8
			
            if nums[mid] == target: #9
                index = mid #10
                high = mid - 1 #11
            elif nums[mid] > target:  #12
                high = mid - 1 #13
            else:  #14
                low = mid + 1 #15       
        
        return index
        
#### Helper function 2
  
    def findEndingIndex(self, nums, target):
        index = -1
        low, high = 0, len(nums) -1
        
        while low <= high:
            
            mid = low + (high - low)//2
            
            if nums[mid] == target:
                index = mid
                low = mid + 1 #16
            elif nums[mid] > target: 
                high = mid - 1
            else:
                 low = mid + 1
            
            
        
        return index