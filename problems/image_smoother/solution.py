class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m, n = len(img), len(img[0])
        ans = [[0 for _ in range(n)] for _ in range(m)]
        
        def valid(x, y):
            if x >= 0 and x <= m-1 and y >= 0 and y <= n-1:
                return True
            else:
                return False
            
            
        for i in range(m):
            for j in range(n):
                cnt = 0 
                val = 0 
                for x in range(-1, 2): # -1, 0, 1
                    for y in range(-1, 2): # -1, 0, 1
                        
                        if valid(i+x, j+y):
                            
                            cnt += 1
                            val += img[i+x][j+y]
                
                ans[i][j] = val // cnt
        
        return ans 