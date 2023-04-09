class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        d = Counter(nums)
        z = 0
        n = len(nums)
        def check(m):
            left = 0
            c = 0
            for right in range(n):
                if left!=right and nums[right]-nums[left]<=m:
                    c+=1
                    left = right+1
                else:
                    left = right
            return c>=p
                    
                
            
            
        
        for i in d:
            z += d[i]//2
        if z>=p: return 0
        else:
            nums.sort()
            l = 0
            r = nums[-1] - nums[0]+1
            ans = 0
            while l<r:
                m = (l+r)//2
                if check(m):
                    ans = m
                    r = m
                else:
                    l = m+1
            return ans