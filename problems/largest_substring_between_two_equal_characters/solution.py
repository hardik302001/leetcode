class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        p = set(s)
        ans = 0
        f = 0
        for i in p:
            l = s.find(i)
            r = s.rfind(i)
            if l!=r:
                f = 1
                ans = max(ans, r-l-1)
            
        return ans if f else -1