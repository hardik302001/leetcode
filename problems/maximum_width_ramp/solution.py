
# approach 1 : brute force : O(N^2)..


# -----------------------------------------------------------------------------------------


# approach 2 : sort values, and update minimum index
# TC: O(nlogn)

# Initial mx ramp = 0
# Initial min index (ind) = float("inf")
# Register every index of every number in "index" collection because there can be duplicate numbers.
# Sort A
# For every number in sorted A, get difference between last index of current number (index[num][-1]) and minimum index of previous numbers (ind).



class Solution:
    def maxWidthRamp(self, A):
        ind = 10**12
        
        index = collections.defaultdict(list)
        for i, num in enumerate(A):
            index[num].append(i)
            
        ramp = 0
        for num in sorted(A):
            ramp = max(ramp, index[num][-1] - ind)      # update maximum answer for increasing num
            ind = min(ind, index[num][0])               # update minimum index
        return ramp 
    
    

    
    
# ------------------------------------------------------------------------------------

# approach 3
# TC : O(n)
# idea: https://leetcode.com/problems/maximum-width-ramp/discuss/265701/java-o-n-detailed-explanation-of-sliding-window-based-solution-beats-100

'''

class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        n = len(nums)
        rmax = [-1]*n
        rmax[-1] = nums[-1]
        for i in range(n-2, - 1, -1):
            rmax[i] = max(rmax[i+1] , nums[i])
        
        ramp = 0
        left = 0
        right = 0
        
        while right<n:
            while left< right and nums[left]>rmax[right]:
                left +=1
                
            ramp = max(ramp , right - left)
            right +=1
        
        return ramp
    
    
'''    


        