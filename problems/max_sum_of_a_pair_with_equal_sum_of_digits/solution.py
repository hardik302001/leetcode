class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        d = {}
        
        x = -1
        for i in nums:
            p = i
            s = 0
            while p>0:
                s += p%10
                p = p//10
            
            if s not in d:
                d[s] = []
            d[s].append(i)
        
        
        res = -1
        for i in d:
            d[i].sort()
            if len(d[i])>1:
                res = max(res , d[i][-1] + d[i][-2])
        return res