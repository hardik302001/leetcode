class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights.append(0)   
        stack = [-1]   #stack.top = -1
        ans = 0
        for i in range(len(heights)):
            while heights[i] < heights[stack[-1]]:  
                p= stack.pop()
                print(p)
                height = heights[p]
                width = i - stack[-1] - 1 #i i s right point  , stack[-1] is left pointer
                ans = max(ans, height * width)
            stack.append(i) #index of height array
        heights.pop()
        return ans
    
    
    
    
    
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        h, w = len(matrix), len(matrix[0])
        m = [[0]*w for _ in range(h)]
        for j in range(h):
            for i in range(w):
                if matrix[j][i] == '1':
                    m[j][i] = m[j-1][i] + 1
        for i in range(h):
            for j in range(w):
                print(m[i][j],end = " ")
            print()
        ma = 0
        for row in m:
            print(row) #this row is itself a histogram
            ma = max(ma,self.largestRectangleArea(row))
        return ma
