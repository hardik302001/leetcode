# O(n)

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        d  = Counter()
        n = len(s)
        l = 0
        m = 0  #max freq
        ans = 0
        for r in range(n):
            d[s[r]]+=1
            if d[s[r]]>m:
                m = d[s[r]]
            
            if (r-l+1 - m>k):
                if(d[s[l]]==m): m-=1   # updating maxi..
                d[s[l]]-=1
                l+=1

            ans = max(ans, r-l+1)
        return ans
        
            