
class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        l = 0
        n = len(s)
        ans = 1
        if n==1: return 1
        c = 0
        
        
        i = 0
        while i<n:
            j = i
            c = 0
            while j+1<n and ord(s[j]) +1== ord(s[j+1]):
                j +=1
                ans = max(ans, j-i+1)
                
            i = j+1
        return ans
                
                