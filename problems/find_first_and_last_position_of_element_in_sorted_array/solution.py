class Solution(object): 
    def searchRange(self, nums, target):
        result = [-1, -1] #1
        if len(nums)==0: return result
        
        result[0] = self.findStartingIndex(nums, target)  #2 
        result[1] = self.findEndingIndex(nums, target)  #3
        if len(nums)==1: return [-1, -1] if nums[0]!=target else [0,0]
        return result #4
		
#### Helper function 1 

    def findStartingIndex(self, nums, target):
        index = -1 #5 
        low, high = 0, len(nums) #6
        if nums[low]==target: return low
        while low < high: #7
            mid = low + (high - low)//2 #8
			
            if nums[mid] == target: #9
                index = mid #10
                high = mid #11
            elif nums[mid] > target:  #12
                high = mid #13
            else:  #14
                low = mid + 1 #15       
        
        return index
        
#### Helper function 2
  
    def findEndingIndex(self, nums, target):
        index = -1
        low, high = 0, len(nums)
        if nums[high-1]==target: return high-1
        while low < high:
            mid = low + (high - low)//2
            if nums[mid] == target:
                index = mid
                low = mid+1 #16
            elif nums[mid] > target: 
                high = mid
            else:
                low = mid + 1
            
        return index