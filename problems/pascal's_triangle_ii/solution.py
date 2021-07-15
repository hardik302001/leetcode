class Solution:
    def getRow(self, numRows: int) -> List[int]:
        numRows +=1
        if numRows   == 0: return []
        Tri = [[1]]
        for i in range(1,numRows):
            row = [1]
            for j in range(1,i):
                row.append(Tri[i-1][j-1] + Tri[i-1][j]) 
            row.append(1)
            Tri.append(row)
        return Tri[-1]