class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        rc = len(matrix)
        cc = len(matrix[0])
        rmi = []
        cma = []
  
        for i in range(rc):
            m = 1000000
            for j in range(cc):
                m = min(m, matrix[i][j])
            rmi.append(m)
            
        for j in range(cc):
            m = 0
            for i in range(rc):
                m = max(m, matrix[i][j])
            cma.append(m)
         
        res = []
        for i in range(rc):
            for j in range(cc):
                if matrix[i][j] == rmi[i] and matrix[i][j]==cma[j]:
                    res.append(matrix[i][j])
        return res