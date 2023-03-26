class Solution:
    def kItemsWithMaximumSum(self, numOnes: int, numZeros: int, numNegOnes: int, k: int) -> int:
        pos = min(k , numOnes)
        k-=pos
        if(k==0): return pos
        z = min(k , numZeros)
        k-=z
        if(k==0): return pos 
        neg = min(k, numNegOnes)
        k-=neg
        if(k==0): return pos  -neg
        