class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows   == 0: return []
        elif numRows == 1: return [[1]]
        Tri = [[1]]
        for i in range(1,numRows):
            row = [1]
            for j in range(1,i):
                row.append(Tri[i-1][j-1] + Tri[i-1][j]) 
            row.append(1)
            Tri.append(row)
        return Tri