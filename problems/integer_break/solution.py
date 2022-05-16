# make it to factors of 2 and 3
# 3*3 > 2*2*2

class Solution:
    def integerBreak(self, n: int) -> int:
        if(n==2): return 1
        if(n==3): return 2
        if(n==4): return 4
        divide = n//3
        remainder=n%3
        if(remainder==0): return (3**divide)
        if(remainder==1): return (3**(divide-1))*4     # n = 7 , bcz 3*3*1 < 3*2*2
        if(remainder==2): return (3**divide)*2       # n = 8 , bcz 3*3*2
        