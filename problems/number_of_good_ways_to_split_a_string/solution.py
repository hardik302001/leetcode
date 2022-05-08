class Solution:
    def numSplits(self, s: str) -> int:
        n =len(s)
        
        ss = set()
        p = [0]*n
        p[0] = 1
        ss.add(s[0])
        for i in range(1,n):
            if s[i] in ss:
                p[i] = p[i-1]
            else:
                ss.add(s[i])
                p[i] = p[i-1] + 1
        
        ss = set()
        q = [0]*n
        q[n-1] = 1
        ss.add(s[n-1])
        for i in range(n-2,-1,-1):
            if s[i] in ss:
                q[i] = q[i+1]
            else:
                ss.add(s[i])
                q[i] = q[i+1] + 1
        
        c = 0
        for i in range(n-1):
            if p[i]==q[i+1]: c+=1
        return c
                
                