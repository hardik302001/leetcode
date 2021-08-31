# https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/discuss/514468/4-Python-Solutions






# O(m+n) solution
# Counting the negatives in each row:

class Solution(object):
    def countNegatives(self, grid):
        i = len(grid)-1
        j = 0
        count = 0
        while i>=0 and j< len(grid[0]):
            print(i,j)
            if grid[i][j] < 0:
                count +=len(grid[0])-j
                i -= 1
            else:
                j +=1
        return(count)