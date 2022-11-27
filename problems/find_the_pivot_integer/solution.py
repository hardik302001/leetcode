class Solution:
    def pivotInteger(self, n: int) -> int:
        x = -1
        for i in range(1, n+1):
            tot = n*(n+1)//2  
            if i*(i+1)//2 == tot - i*(i-1)//2:
                x = i
        return x