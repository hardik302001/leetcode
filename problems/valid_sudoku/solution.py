class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        T = zip(*board)   

        return (
            True if self.is_row_valid(board) 
            and self.is_row_valid(T) 
            and self.is_square_valid(board)
            else False
        )
        
        
    def is_row_valid(self, board: List[List[str]]) -> bool:
        for row in board:
            digits = [ch for ch in row if ch.isdigit()]

            if len(digits) != len(set(digits)):
                return False
        
        return True
    
    
    def is_square_valid(self, board: List[List[str]] ) -> bool:
        for i in range(0,9,3):
            for j in range(0,9,3):
                square = [board[row][col] for row in range(i, i+3) for col in range(j, j+3)]
                flat = [
                    square[row][col] 
                    for row in range(len(square)) 
                    for col in range(len(square[0])) 
                    if square[row][col].isdigit()
                ]
                
                if len(flat) != len(set(flat)):
                    return False
                
        return True   
