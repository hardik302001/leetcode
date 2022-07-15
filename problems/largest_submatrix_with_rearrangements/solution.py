# similar to https://leetcode.com/problems/maximal-rectangle/
# but here we can choose a bunch of bars and sort them

class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        if not matrix:
            return 0
        row , cols = len(matrix), len(matrix[0])
        m = matrix             
        
        for i in range(1 , row):
            for j in range(cols):
                if matrix[i][j] == 1: 
                    m[i][j] = m[i-1][j] + 1    
        
        
        
        ans = 0
        for i in range(row):
            m[i].sort()
            # print(m[i])
            width = 0
            height = 0
            for j in range(cols):
                if m[i][j]==0 :
                    continue
                else: 
                    width = (cols-j)
                    height = max(m[i][j], height)
                    ans = max(ans, width*height)
        return ans