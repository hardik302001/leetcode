class Solution:
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        c = 0
        n = len(s)
        for i in range(n):
            for j in range(i+1, n):
                if (j-i+1)%2==0:
                    if s[i:(i+j)//2+1]=="0"*((j-i+1)//2) and s[(i+j)//2+1:j+1]=="1"*((j-i+1)//2):
                        c = max(c, (j-i+1))
        return c