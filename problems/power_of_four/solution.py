class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n==1:
            return True
        if (n&(n-1)==0 and (n-1)%3==0) and n>0:
            return True
        return False