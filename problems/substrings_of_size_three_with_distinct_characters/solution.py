class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        n = len(s)
        if n==1 or n==2:
            return 0
        else:
            c = 0
            for i in range(0,n-2):
                if len(set(s[i:i+3]))==3:
                    c =c +1
                    print(s[i:i+3])
            return c
        