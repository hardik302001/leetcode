class Solution:

    def fib(self, n):
        m = 1000000007
        a = 0
        b = 1
        if n == 0:
            return 0
        elif n == 1:
            return b
        else:
            for i in range(1, n):
                c = (a + b)
                a = b
                b = c
            return b
        
    def countHousePlacements(self, n: int) -> int:
        return pow(self.fib(n+2), 2, 1000000007)