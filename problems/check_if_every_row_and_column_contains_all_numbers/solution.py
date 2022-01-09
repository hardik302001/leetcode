class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        n = len(matrix)
        p = [i+1 for i in range(n)]
        
        for row in matrix:
            if sorted(row)!=p:
                # print(sorted(row), p)
                return 0
        
        tmatrix = zip(*matrix)
        for row in tmatrix:
            if sorted(row)!=p:
                # print(sorted(row), p)
                return 0
        return 1