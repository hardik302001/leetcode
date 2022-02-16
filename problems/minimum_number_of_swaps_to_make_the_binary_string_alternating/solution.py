class Solution:
    def minSwaps(self, s: str) -> int:
        o = s.count('1')
        z = s.count('0')
        
        n = len(s)
        
        if n&1:
            if o==z+1:
                p = "10"*((n+1)//2)
                p = p[:n]
                c = 0
                for i in range(n):
                    if p[i]!=s[i]:
                        c = c + 1
                return c//2
            elif z==o+1:
                p = "01"*((n+1)//2)
                p = p[:n]
                c = 0
                for i in range(n):
                    if p[i]!=s[i]:
                        c = c + 1
                return c//2
            else:
                return -1
        else:
            if o==z:
                p1 = "10"*(n//2)
                p2 = "01"*(n//2)
                c1 = 0
                c2 = 0
                for i in range(n):
                    if p1[i]!=s[i]:
                        c1 = c1 + 1
                    if p2[i]!=s[i]:
                        c2 = c2 + 1
                return min(c1//2 , c2//2)
            else:
                return -1