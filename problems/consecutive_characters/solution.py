class Solution:
    def maxPower(self, s: str) -> int:
        m = 1
        n = len(s)
        p = s[0]
        c = 1
        for i in range(1,n):
            if s[i]==p:
                c = c + 1
            else:
                c = 1
                p = s[i]
            m =max(m,c)
        return m