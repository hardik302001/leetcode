class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        a, e ,i ,o, u = 0 , 0 ,0 ,0 ,0
        l = 0
        ans = 0
        n = len(s)
        
        for r in range(n):
            if s[r]=='a':
                a+=1
            elif s[r]=='e':
                e+=1
            elif s[r]=='i':
                i+=1
            elif s[r]=='o':
                o+=1
            elif s[r]=='u':
                u+=1
                
            while (r-l+1>k):
                if s[l]=='a':
                    a-=1
                elif s[l]=='e':
                    e-=1
                elif s[l]=='i':
                    i-=1
                elif s[l]=='o':
                    o-=1
                elif s[l]=='u':
                    u-=1
                l+=1
            ans = max( ans , a+e+i+o+u)
        return ans