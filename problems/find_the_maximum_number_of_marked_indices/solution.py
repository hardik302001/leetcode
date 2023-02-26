class Solution:
    def maxNumOfMarkedIndices(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0 
        
        # match smaller elements with other half
        j = len(nums)-1
        for i in range(len(nums)//2-1, -1, -1): 
            if nums[i]*2 <= nums[j]: 
                ans += 2
                j -= 1
        return ans 