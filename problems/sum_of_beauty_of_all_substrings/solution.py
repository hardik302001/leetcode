# TC: O(26 * n^2)
# BRUTE FORCE

class Solution:
    def beautySum(self, s: str) -> int:
        ans = 0
        n = len(s)
        for i in range(n):
            d = {}
            for j in range(i, n):
                if s[j] in d:
                    d[s[j]]+=1
                else:
                    d[s[j]] = 1
                    
                ma = max(d.values())
                mi = min(d.values())
                ans = ans + (ma - mi)
                
                
        return ans
                