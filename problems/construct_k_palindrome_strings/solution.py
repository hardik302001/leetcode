class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        d = Counter()
        for i in s:
            d[i]+=1
        n = len(s)
        c = 0
        if k>n:
            return 0
        if k==n:
            return 1
        
        for i in d:
            if d[i]&1:
                c+=1
                
        
        if c>k:
            return 0
        elif c==k:
            return 1
        else:
            return 1
            