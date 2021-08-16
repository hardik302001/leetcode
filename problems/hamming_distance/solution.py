class Solution:

    def hammingDistance(self, x: int, y: int) -> int:
        def c(n):
            if (n == 0):
                return 0
            else:
                return 1 + c(n & (n - 1))
             
        #no of set bits in xor
        p = x^y
        return c(p)
    
    