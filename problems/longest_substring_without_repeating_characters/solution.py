# see cpp soln, thats somewhat better maybe..
#sliding window


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        m = 0
        d = {}
        n = len(s)
        
        for r in range(n):
            if s[r] in d:
                d[s[r]]+=1
            else:
                d[s[r]] = 1
            
            while d[s[r]]>1:
                d[s[l]]-=1
                l = l +1
                
            m = max(m,r-l+1)
        return m