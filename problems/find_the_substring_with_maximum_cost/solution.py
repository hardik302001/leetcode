class Solution:
    def maximumCostSubstring(self, s: str, chars: str, vals: List[int]) -> int:
        c = 0
        d = {}
        for i in range(1, 27):
            x = chr(97 + i-1)
            if x in chars:
                d[x] = vals[chars.index(x)]
            else:
                d[x] = i
        l = 0
        ma = 0
        n = len(s)
        for r in range(n):
            c += d[s[r]]
            if c>=0:
                ma = max(ma , c)
            else:
                c = 0
        
        return ma
            