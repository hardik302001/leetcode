// backtracking


// see takeyouforward video : 
// https://takeuforward.org/data-structure/sudoku-solver/

// also see : M COLORING PROBLEM striver and gfg, exact same pseudo code
// also see: KNIGHT TOUR , https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

// try all variations , if current chouce if valid , then go for next state, if next state is possible , then current state is possible ,else if next state is not possible 


// also see: RAT IN MAZE : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1


class Solution {
public:
    
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);        
    }
    
    bool solve(vector<vector<char>>& board){  // why we needed bool here , bcz we dont know if we will get correct position or not, usually we know we will reach our final state in backtracking , but not here , bcz we need correct answers..
        
        
        int sz = 9;

        for(int i = 0;i<sz; i++){
            for(int j = 0;j<sz;j++){
                if(board[i][j]=='.'){
                    for(char x = '1' ;x<= '9' ;x++){
                        if(valid(i , j , x , board , sz)){  // if we can keep x at cur position
                            board[i][j] = x;
                            if(solve(board)){
                               return true; 
                            }else{
                                board[i][j] = '.';   // bcz next state is not possible so backtrack
                            }
                        }                    
                    }
                    return false;  // bcz none of the choice is possible according to our current situation of board ,so return false
                }
            }
        }
         
        return true;   // all places are filled , none of them are left
    }
    
    
    bool valid(int row , int col , char x, vector<vector<char>>& board , int sz){
        for(int i = 0;i<9;i++){
            if(board[i][col]==x)return false;
            if(board[row][i]==x)return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3]==x)return false;
        }
        return true;
    }
    
};


/*
here , n = 9
Time Complexity: O(9(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.

Space Complexity: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.

*/
