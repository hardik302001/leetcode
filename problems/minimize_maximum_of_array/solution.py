
# O(n)  : obsrvations
'''
If we encounter a number higher than the previous maximum, we know that we can increase the previous elements to decrease this higher number and the new maximum will be the sum of all elements divided by the number of elements (rounded up).
'''


class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:    
        res=0
        maxi=nums[0]
        s=nums[0]
        for i in range (1,len(nums)):
            s+=nums[i]
            if nums[i]>maxi:
                maxi=ceil(s/(i+1))
            res=max(maxi,res)
        return res

# ----------------------------------------------------------

# binary search

'''
class Solution:
    def minimizeArrayValue(self, p: List[int]) -> int:
            
        def check(m , p):
            
            nums = p[:]
            n = len(nums)
            for i in range(n-1,0 , -1 ):
                if nums[i]>m:
                    dif = nums[i]-m
                    nums[i-1]+=dif
                    nums[i]-=dif
        
            for i in nums:
                if i>m:
                    return 0
            return 1
            
            
            
        
        l = 1
        ans = max(p)
        r = max(p)+1
    
        
        while l<r:
            m = (l + r)//2
            if check(m , p):
                ans = m
                r = m
            else:
                l = m+1
        return ans
'''