class Solution:
    def longestPalindrome(self, s: str) -> int:
        d = {}
        for i in s:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
        ans = 0
        f = 0
        for i in d:
            if d[i]%2==0:
                ans+=d[i]
            else:
                f = 1
                if d[i]>1:
                    ans = ans + d[i]-1
                
        return ans + f