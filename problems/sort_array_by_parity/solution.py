class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        e = []
        o =[]
        #O(n) time
        #O(n) space
        
        
        #for O(1) space implement using quicksort
        
        
        for i in nums:
            if i%2:
                o.append(i)
            else:
                e.append(i)
        return e+o