class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        p = 'aeiouAEIOU'
        d = 0
        n = len(s)
        for i in range(n//2):
            if s[i] in p:
                d = d + 1
        for i in range(n//2,n):
            if s[i] in p:
                d = d -1
        return not d
                