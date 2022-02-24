
# see solution section


'''
# TC: O(n) , SC: O(n)
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        
        n = len(nums)

        s = list(set(nums))
        actual = n*(n+1)//2 - sum(s)
        rep = actual + sum(nums) - n*(n+1)//2
        
        
        return [rep  , actual]
    

'''

# https://leetcode.com/problems/find-all-duplicates-in-an-array/
# https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
# TC: O(n) , SC: O(1)

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        
        n = len(nums)
        p = nums[:]     

        for i in range(n):
            x = nums[i]
            nums[abs(x)-1]*= -1   
            if nums[abs(x)-1]>0:
                rep = abs(nums[i])
                
                
        

        for i in range(n):
            x = abs(p[i])
            if p[x-1]>0:
                p[x-1]*=-1
                
        for i in range(n):
            if p[i]>0:
                actual = i+1
                break
            
            
        return [rep  , actual]
        