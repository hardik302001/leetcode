class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        for i in range(n-1):
            p = s[:i+1]
            np = len(p)
            if n%np==0:
                d = n//np
                if p*d==s:
                    return True
        return False
            