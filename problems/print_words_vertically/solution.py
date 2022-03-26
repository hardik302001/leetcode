class Solution:
    def printVertically(self, s: str) -> List[str]:
        p = s.split()
        l = []
        m = len(max(p , key = len))
        ans = []
        for i in p:
            l.append(i + ' '*(m-len(i)))
        
        r = len(l)
        c = m
        
        for i in range(c):
            z = ''
            for j in range(r):
                z+= l[j][i]
            ans.append(z)
        res = []
        for z in ans:
            z = z.rstrip()
            res.append(z)
        return res
        