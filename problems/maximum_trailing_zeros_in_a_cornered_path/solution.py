class Solution:
    def maxTrailingZeros(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        
        mat = []
        for row in grid:
            p = []
            for x in row:
                f = 0
                t = 0
                while x%5==0:
                    x//=5
                    f+=1
                while x%2==0:
                    x//=2
                    t+=1
                p.append([t , f])
            mat.append(p)
            
        
        trans = zip(*mat)
        
        rowpref = []
        for row in mat:
            pp = []
            pp.append([0,0])
            for i in range(m):
                pp.append([pp[i][0] + row[i][0] , pp[i][1] + row[i][1]])
            rowpref.append(pp)
        
        colpref = []
        for col in trans:
            pp = []
            pp.append([0,0])
            for i in range(n):
                pp.append([pp[i][0] + col[i][0] , pp[i][1] + col[i][1]])
            colpref.append(pp)
        
        c = 0
        # print(rowpref)
        # print(colpref)
                
        for i in range(n):
            for j in range(m):
                cur = mat[i][j]
                left = [rowpref[i][j][0]  , rowpref[i][j][1] ]
                right = [rowpref[i][m][0] - rowpref[i][j+1][0]  ,rowpref[i][m][1] - rowpref[i][j+1][1] ]
                up = [colpref[j][i][0]  , colpref[j][i][1] ]
                down = [colpref[j][n][0] - colpref[j][i+1][0]  , colpref[j][n][1] - colpref[j][i+1][1]]
                
                # print(up , down , left , right)
                ma = max(min(left[0] + cur[0] + up[0] , left[1] + cur[1] + up[1] ) , 
                         min(left[0] + cur[0] + down[0] , left[1] + cur[1] + down[1] ) ,
                         min(right[0] + cur[0] + up[0] , right[1] + cur[1] + up[1] ) ,
                         min(right[0] + cur[0] + down[0] , right[1] + cur[1] + down[1] ) 
                        )
                
                c = max( c , ma)
                
        
        
        
        
        
        
        
        
        
        
        return c