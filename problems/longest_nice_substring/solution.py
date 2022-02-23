class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        ans = ""
        m = 0
        for j in range(len(s)):
            for i in range(j):
                t = s[i : j+1]
                if set(t) == set(t.swapcase()):
                    if len(t)>m:
                        ans = t
                        m = len(t)
        return ans 