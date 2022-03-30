# same as : https://leetcode.com/problems/binary-search/   

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False

        l, r = 0, len(matrix)*len(matrix[0])-1

        while l<r:
            mid = (l+r)//2
            i, j = mid//len(matrix[0]), mid%len(matrix[0])

            if matrix[i][j]>=target:          # greater and equal for r = mid
                r = mid
            else:
                l = mid + 1
        # print(l)
        x, y = l//len(matrix[0]), l%len(matrix[0])
        return matrix[x][y]==target