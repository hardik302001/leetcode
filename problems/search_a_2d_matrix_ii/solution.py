# we cant do binary search here , bcz if we open matrix in form of one single list, it wont be in increasing order


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