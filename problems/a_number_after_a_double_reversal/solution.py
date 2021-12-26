class Solution:
    def isSameAfterReversals(self, num: int) -> bool:
        n = str(num)
        r1 = n[::-1]
        
        r1 = int(r1)
        r1 = str(r1)
        
        r2 = r1[::-1]
        
        return (r2==n)
        