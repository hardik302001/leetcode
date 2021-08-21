class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        d = []
        c = 0
        for i in matrix:
            for j in i:
                if j<0:
                    c =c +1
                d.append(abs(j))
        if c%2==0:
            return sum(d)
        else:
            return sum(d) - 2*min(d)
        
        