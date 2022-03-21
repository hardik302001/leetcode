class Solution:
    def minOperations(self, nums: List[int]) -> int:
        m = 0
        ans = 0
        n = len(nums)
        for i in nums:
            c = 0
            d = 0
            while i>0:
                if i&1:
                    i-=1
                    d+=1
                else:
                    c+=1
                    i//=2
                
            m = max( m , c)
            ans += d
        return ans+m
        
