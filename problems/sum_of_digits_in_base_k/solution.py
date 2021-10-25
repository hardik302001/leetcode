class Solution:
    def sumBase(self, n: int, k: int) -> int:
        s = ''
        while n>0:
            s = s+ str(n%k)
            # print(n)
            n = n//k
        s = s+ str(n)
        print(s)
        c = 0
        for i in s:
            c =c + int(i)
        return c
        