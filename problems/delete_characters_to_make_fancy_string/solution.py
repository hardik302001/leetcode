class Solution:
    def makeFancyString(self, s: str) -> str:
        p = []
        n = len(s)
        c = 1
        for i in range(1,n):
            if s[i]==s[i-1]:
                c =c +1
            else:
                p.append([s[i-1],c])
                c = 1
        p.append([s[n-1],c])
        ans = ''
        for i in p:
            x = i[1]
            if i[1]>=3:
                x = 2
            ans = ans + i[0]*x
            
        return ans
        