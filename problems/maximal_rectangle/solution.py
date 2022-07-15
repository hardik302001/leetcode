# also see: https://leetcode.com/problems/largest-submatrix-with-rearrangements/


# you can also dp , without extra space on actual matrix

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
                
            # print(m)
            m = arr[i]* (left_diff +  right_diff+1)
            ans = max(ans ,m)
            
        return ans
    
    
    
    
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
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

        ma = 0
        for row in m:
            # print(row) #this row is itself a histogram
            x = self.largestRectangleArea(row)
            ma = max(ma,x)
            
        return ma
