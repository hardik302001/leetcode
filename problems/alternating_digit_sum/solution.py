class Solution:
    def alternateDigitSum(self, n: int) -> int:
        x = 0
    
        p = str(n)
        if len(p)&1:
            f = 1
        else:
            f = -1
        while n>0:
            x += f*(n%10)
            f = -1*f
            n = n //10
        return x