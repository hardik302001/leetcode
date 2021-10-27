class Solution:
    def countBalls(self, low: int, high: int) -> int:
        d = {}
        for i in range(low, high+1):
            s  = 0
            for ii in str(i):
                s = s+ int(ii)
            
            if s in d:
                d[s]+=1
            else:
                d[s] = 1
        
        return max(d.values())