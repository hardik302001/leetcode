class Solution:
    def minSteps(self, s: str, t: str) -> int:
        d = Counter()
        
        for i in s:
            d[i]+=1
        for i in t:
            d[i]-=1
        
        c =0
        for i in d:
            c += abs(d[i])
        return c