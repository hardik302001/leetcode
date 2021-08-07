class Solution:
    def checkMove(self, b: List[List[str]], r: int, c: int, col: str) -> bool:
        b[r][c] = col
        # for i in b:
        #     print(i)
        # print()
        f = 0
        for i in range(r-1,-1,-1):
            if b[i][c]=='.':
                break
            if b[i][c]==col:
                if f == 1:
                    return True
                else:
                    break
            if b[i][c]!=col and b[i][c]!='.':
                f = 1
        # print(1)
        f = 0
        for j in range(c-1,-1,-1):
            if b[r][j]=='.':
                break
            if b[r][j]==col:
                if f == 1:
                    return True
                else:
                    break
            if b[r][j]!=col and b[r][j]!='.':
                f = 1
        # print(2)
        f = 0
        for i in range(r+1,8):
            if b[i][c]=='.':
                break
            if b[i][c]==col:
                if f == 1:
                    return True
                else:
                    break
            if b[i][c]!=col and b[i][c]!='.':
                f = 1
        # print(3) 
        f = 0
        for j in range(c+1,8):
            if b[r][j]=='.':
                break
            if b[r][j]==col:
                if f == 1:
                    return True
                else:
                    break
            if b[r][j]!=col and b[r][j]!='.':
                f = 1 
        # print(4)
        f = 0
        x = r-1
        y = c-1
        for z in range(min(r,c)):
            if b[x][y]=='.':
                break
            if b[x][y]==col:
                if f == 1:
                    return True
                else:
                    break
            if b[x][y]!=col and b[x][y]!='.':
                f = 1
            x = x -1
            y = y-1
        # print(5)
        f = 0
        x = r+1
        y = c-1
        for z in range(min(8 -r-1,c)):
            if b[x][y]=='.':
                break
            if b[x][y]==col:
                if f == 1:
                    return True
                else:
                    break
            if b[x][y]!=col and b[x][y]!='.':
                f = 1
            x = x+1
            y = y-1
            
        # print(6)
        f = 0
        x = r+1
        y = c+1
        for z in range(min(8 -r-1,8-c-1)):
            if b[x][y]=='.':
                break
            if b[x][y]==col:
                if f == 1:
                    return True
                else:
                    break
            if b[x][y]!=col and b[x][y]!='.':
                f = 1
            x = x+1
            y = y+1
            
        # print(7)
        f = 0
        x = r-1
        y = c+1
        for z in range(min(r,8-c-1)):
            if b[x][y]=='.':
                break
            if b[x][y]==col:
                if f == 1:
                    return True
                else:
                    break
            if b[x][y]!=col and b[x][y]!='.':
                f = 1
            x = x-1
            y = y+1
        # print(8) 
        return False