# if we sort it, then first condition will be satisfied without any issue.
# so for section condition we need to divide it groups of szie 1, 2, 3, 4...
# we can do binary search for l*(l+1)//2 <= n

class Solution:
    def maximumGroups(self, nums: List[int]) -> int:
            
        
        n = len(nums)
        l = 1
        r = 10000
        ans = 0
        while l<r:
            m = (l+r)//2
            if m*(m+1)//2 == n:   return m
            elif m*(m+1)//2 > n:  r = m
            else:                 l = m+1
        return l-1
        

# ---------------------------------------------------------------------------------------------
# O(nlogn)
'''
class Solution:
    def maximumGroups(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        ans = 0
        su = 0
        i = 0
        count = 0
        prev = 0
        
        while i<n:
            su = 0
            count = count+1
            cur = 0
            while i<n and cur<count:
                su+= nums[i]
                i+=1
                cur+=1
                   
            if su>prev and cur==count:
                ans+=1
                i-=1
            prev = su
        
            i+=1
            
            
        return ans
'''