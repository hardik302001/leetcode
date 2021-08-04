class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        ans = 0
        for i in range(8):
            for j in range(8):
                ele = board[i][j]
                if ele=='R':
                    x = i
                    y = j
        for j in range(y-1,-1,-1):
            # print(board[x][j])
            if board[x][j]=='p':
                ans = ans +1
                break
            elif board[x][j]=='.':
                continue
            else:
                break
        
        for j in range(y+1,8):
            # print(board[x][j])
            if board[x][j]=='p':
                ans = ans +1
                break
            elif board[x][j]=='.':
                continue
            else:
                break
                
        for i in range(x+1,8):
            # print(board[i][y])
            if board[i][y]=='p':
                ans = ans +1
                break
            elif board[i][y]=='.':
                continue
            else:
                break
        for i in range(x-1,-1,-1):
            # print("ch " ,board[i][y])
            if board[i][y]=='p':
                ans = ans +1
                break
            elif board[i][y]=='.':
                continue
            else:
                break
                
            
        return ans