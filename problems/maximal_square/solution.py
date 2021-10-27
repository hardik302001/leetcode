#dp
#dp[i][j] tells aximum possible sqaure len of sqaure that can be formed having mat[i][j] as its bottom right corner 
# see SOLUTION SECTION SECOND SOLUTION
# TC, SC = O(m*n)


'''
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if matrix is None or len(matrix) < 1:
            return 0
        
        rows = len(matrix)
        cols = len(matrix[0])
        
        dp = [[0]*(cols+1) for _ in range(rows+1)]    #extra row and column, so you can easily code
        max_side = 0
        
        for r in range(rows):
            for c in range(cols):
                if matrix[r][c] == '1':
                    dp[r+1][c+1] = min(dp[r][c], dp[r+1][c], dp[r][c+1]) + 1 # Be careful of the indexing since dp grid has additional row and column
                    max_side = max(max_side, dp[r+1][c+1])
                
        return max_side * max_side
    
'''
    
#well you dont even need extra space
#you can change the matrix only, bcz we are just updating once!
#try visualising with the sample test case!
#TC = O(mn)
#SC = O(1)


class Solution:
    def maximalSquare(self, matrix):
        rows,cols,max_size = len(matrix),len(matrix[0]),0
        for row in range(rows):
            for col in range(cols):
                matrix[row][col] = int(matrix[row][col])
                if matrix[row][col] >= 1:
                    if row-1 >= 0 and col-1 >= 0:
                        matrix[row][col] = min(matrix[row-1][col],matrix[row][col-1],matrix[row-1][col-1])+1
                    max_size = max(max_size,matrix[row][col])
                    
        return max_size*max_size