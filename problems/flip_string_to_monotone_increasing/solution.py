#first i calculated for p = 111111111   (all one)
#then at each step while traversing i change evry 1 to 0, so that now p = 0111111, p = 00111111, p = 000111111.. and so on till all 0000000

#and took minimum of all answers


class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
    
        n = len(s)
        c = 0
        p = '1'*n   #all one
        for i in range(n):
            if p[i]!=s[i]:
                c =c +1
        ans = c
        for i in s:
            if i=='1':
                c =c+1
                ans= min(ans, c)
            if i=='0':
                c = c -1
                ans = min(ans, c)
        return ans