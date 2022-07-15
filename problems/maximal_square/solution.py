# very similar to maximal rectangle, just update side as min( height , width)
# also see: https://leetcode.com/problems/count-square-submatrices-with-all-ones/


class Solution:
    def largestRectangleArea(self, arr):
        n = len(arr)
        next_smaller_element = [-1]*n      #monotonic inc stack, left to right
        prev_smaller_element = [-1]*n      #monotonic inc stack, right to left
    
        stack1 = []
        for i in range(n):
            while len(stack1) and arr[stack1[-1]] > arr[i]:
                next_smaller_element[stack1[-1]] = i
                stack1.pop()   
            stack1.append(i)

            
        stack2 = []
        for i in range(n-1,-1,-1):
            while len(stack2) and arr[stack2[-1]] >= arr[i]:
                prev_smaller_element[stack2[-1]] = i
                stack2.pop()
            stack2.append(i)
            
        # print(prev_smaller_element)    
        # print(next_smaller_element)
        ans = 0
        for i in range(n):
            if prev_smaller_element[i]== -1:
                left_diff = i - 0
            else:
                left_diff = (i - prev_smaller_element[i]) - 1
                
            if next_smaller_element[i]== -1:
                right_diff = n-1 - i
            else:
                right_diff = (next_smaller_element[i] - i) - 1
                
            side = min(arr[i] , left_diff +  right_diff + 1)
            ans = max(ans ,side*side)
            
        return ans
    
    
    
    
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        row , cols = len(matrix), len(matrix[0])
        m = [[0]*cols for _ in range(row)]
        
        for i in range(cols):
            m[0][i] = 1 if matrix[0][i]=='1' else 0
        
        for i in range(1 , row):
            for j in range(cols):
                if matrix[i][j] == '1': 
                    m[i][j] = m[i-1][j] + 1            
        
        # for i in range(row):
        #     for j in range(cols):
        #         print(m[i][j],end = " ")
        #     print()
            
            
        ma = 0
        for row in m:
            # print(row) #this row is itself a histogram
            x = self.largestRectangleArea(row)
            ma = max(ma,x)
            
        return ma

    
    
    # tc: O(M*N)
    # SC: O(N)



#dp
#dp[i][j] tells maximum possible sqaure len of sqaure that can be formed having mat[i][j] as its bottom right corner 
# see SOLUTION SECTION SECOND SOLUTION
# TC, SC = O(m*n)


'''
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if matrix is None or len(matrix) < 1:
            return 0
        
        rows = len(matrix)
        cols = len(matrix[0])
        
        dp = [[0]*(cols+1) for _ in range(rows+1)]    # extra row and column, so you can easily code
        max_side = 0
        
        for r in range(rows):
            for c in range(cols):
                if matrix[r][c] == '1':
                    dp[r+1][c+1] = min(dp[r][c], dp[r+1][c], dp[r][c+1]) + 1 # Be careful of the indexing since dp grid has additional row and column
                    max_side = max(max_side, dp[r+1][c+1])
                
        return max_side * max_side
    
'''
    
# well you dont even need extra space
# you can change the matrix only, bcz we are just updating once!
# try visualising with the sample test case!
# TC = O(mn)
# SC = O(1)

# see figure in solution section

'''

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
        
'''