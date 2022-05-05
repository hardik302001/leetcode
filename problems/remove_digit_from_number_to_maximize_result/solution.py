class Solution:
    def removeDigit(self, s: str, d: str) -> str:
        p = []
        n = len(s)
        for i in range(n):
            if s[i]==d:
                p.append(s[:i] + s[i+1:])
        return max(p)