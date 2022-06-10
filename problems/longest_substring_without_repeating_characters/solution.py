class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        ans = 0
        n  = len(s)
        d = Counter()
        
        for r in range(n):
            d[s[r]]+=1
            while d[s[r]]>1:
                d[s[l]]-=1
                l+=1
            ans = max(ans , r-l+1)
            
        return ans