# O(26*n)

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
                d[s[l]]-=1
                l+=1

            # even if you dont update m, it will have no issue , bcz at start of next iteration , it will be updated automatically
            # for i in d:
            #     m = max( m , d[i])
            ans = max(ans, r-l+1)
        return ans
        
            