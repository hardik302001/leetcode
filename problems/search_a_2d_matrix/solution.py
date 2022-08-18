#                       |
#                       |
# we can also do this, \|/


# with binary search, we were able to do binary search bcz, if we open the matrix it will be a single sorted list


class Solution:
    def searchMatrix(self, mat: List[List[int]], x: int) -> bool:
        if mat:
            m, n = len(mat) , len(mat[0])
            r, c = 0,  len(mat[0]) - 1             
            
            '''
            
                 *  *  *  * (*)  <--start frm this elemenet checking in both directions
                 *  *  *  *  *
                 *  *  *  *  *
                 *  *  *  *  *
                 *  *  *  *  *
            
            
            '''
            
            while r<m and c>=0:
                if mat[r][c]==x:
                    return True
                if mat[r][c]<x:
                    r+=1
                else:
                    c-=1
        return False