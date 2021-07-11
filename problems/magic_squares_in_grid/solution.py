class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        def isDistinct(i,j):
            s = []
            p = [1,2,3,4,5,6,7,8,9]
            for x in range(3):
                for y in range(3):
                    s.append(grid[i+x][j+y])
            if sorted(p)==sorted(s):
                return True
            return False
        
        
        def isMagicSquare(i, j, length):
            s = set()
            
            #for all rows
            for x in range(length):
                sum = 0
                for y in range(length):
                    sum += grid[i+x][j+y]
                s.add(sum)
                if len(s)>1:
                    return False
            
            #for all cols
            for y in range(length):
                sum = 0
                for x in range(length):
                    sum += grid[i+x][j+y]
                s.add(sum)
                if len(s)>1:
                    return False
            
            # for forward diagonal
            sum = 0
            for x in range(length):
                sum += grid[i+x][j+x]
            s.add(sum)
            if len(s)>1:
                return False
            
            #for backward diagonal
            sum = 0
            for x in range(length):
                sum += grid[i+x][j+ length - 1 - x]
            s.add(sum)
            if len(s)>1:
                return False
            s = list(s)
            print(s)
            if len(s)==1 and s[0]==15:
                return True

        
        
        
        m = len(grid)
        n = len(grid[0])
        c = 0
        for i in range(m-3+1):
            for j in range(n-3+1):
                #grid[i][j] is top left coord of that squaare
                a = isMagicSquare(i, j, 3)
                b = isDistinct(i,j)
                print(a,b)
                if a and b:
                        c = c +1
        return c
    
                