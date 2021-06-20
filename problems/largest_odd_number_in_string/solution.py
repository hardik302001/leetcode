class Solution:
    def largestOddNumber(self, s: str) -> str:
        s = s[::-1]
        f = 0
        for i in range(len(s)):
            if int(s[i])%2==0:
                continue
            else:
                f = 1
                p =  s[i:]
                break
        if f==1:
            return p[::-1]
        else:
            return ""