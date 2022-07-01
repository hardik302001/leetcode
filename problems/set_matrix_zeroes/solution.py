class Solution:
    def setZeroes(self, mat: List[List[int]]) -> None:
        n = len(mat)   # no f rows
        m = len(mat[0])  # no of cols
        boolr = 0
        boolc = 0
        for i in range(m):
            if mat[0][i] == 0: 
                boolr = 1
                break
        for i in range(n):
            if mat[i][0]==0:
                boolc = 1
                break
        for i in range(1, n):
            for j in range(1 , m):
                if mat[i][j]==0:
                    mat[i][0] = 0  
                    mat[0][j] = 0
        for i in range(1,n):
            for j in range(1,m):
                if mat[i][0]==0 or mat[0][j]==0:
                    mat[i][j] = 0

        if boolc:
            for j in range(n):
                mat[j][0] = 0
        if boolr:
            for i in range(m):
                mat[0][i] = 0
