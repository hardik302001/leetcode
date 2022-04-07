
//  For this, we introduce two new states for a cell:
// 2: newly alive and 3: newly dead

// Now let's see how we will have to modify our neighbour checking function to accomodate these:
// For our intents and purposes (i.e checking the neighbours of a cell), the newly died cell is still alive, since the changes made by us have not been enforced right now.
// Hence the condition curr[x][y] == 1 transforms to curr[x][y] == 1 || curr[x][y] == 3.
// Everything else stays the same here.

// Onto our main function:
// Wherever we were modifying the board, now we use our new states, so any cell that we mark as alive will be marked 2, and any cell which we mark as dead, will be marked 3 instead of 1 and 0 respectively. Then after finishing the whole processing (i.e the entire board), we iterate over the matrix again, replacing our new states (2, 3) with their respective values (1, 0).

class Solution{
public:
    int getLiveNeighbours(vector<vector<int>>& curr, int i, int j, int m, int n) {
        int liveNeighbours = 0;
        if(i>0) {
            //check the upper neighbour
            if(curr[i-1][j] == 1 || curr[i-1][j] == 3) liveNeighbours++;
        }
        if(i<m-1) {
            //check the lower neighbour
            if(curr[i+1][j] == 1 || curr[i+1][j] == 3) liveNeighbours++;
        }
        if(j>0) {
            //check the left neighbour
            if(curr[i][j-1] == 1 || curr[i][j-1] == 3) liveNeighbours++;
        }
        if(j<n-1) {
            //check the right neighbour
            if(curr[i][j+1] == 1 || curr[i][j+1] == 3) liveNeighbours++;
        }

        if(i>0 && j>0) {
            if(curr[i-1][j-1] == 1 || curr[i-1][j-1] == 3) liveNeighbours++;
        }
        if(i>0 && j<n-1) {
            if(curr[i-1][j+1] == 1 || curr[i-1][j+1] == 3) liveNeighbours++;
        }
        if(i<m-1 && j>0) {
            if(curr[i+1][j-1] == 1 || curr[i+1][j-1] == 3) liveNeighbours++;
        }
        if(i<m-1 && j<n-1) {
            if(curr[i+1][j+1] == 1 || curr[i+1][j+1] == 3) liveNeighbours++;
        }
        return liveNeighbours;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                int ln = getLiveNeighbours(board, i, j, m, n);
                if(board[i][j] == 0) {
                    //currently dead
                    //can become alive if has exactly three live neighbours
                    if(ln == 3) {
                        board[i][j] = 2; //newly alive
                    }
                }
                else if(board[i][j] == 1) {
                    //<2 -> die
                    //==2 || ==3 live
                    //>3 ->die
                    if(ln < 2 || ln > 3) {
                        board[i][j] = 3; //newly dead
                    }
                }
            }
        }
        //final modifications 2->1, 3->0
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == 2) board[i][j] = 1;
                else if(board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};
// Complexity
// Time: O(mn), the same as before
// Space: O(1), as everything is done in-place, and with O(1) extra memory.





// ------------------------------------------------------------------------------------



// Approach 1: Remember the board (extra space)
// One way to not let any changes we make affect the choices for other cells, is to:

// Either do the modifications on a new board, and use the old board for checking the neighbours.
// Or make a copy of the old board, and use that for checking, while making modifications on the original board.
// I will go for the second approach on this, but we can implement either of those with similar complexity.
/*

class Solution{
public:
    int getLiveNeighbours(vector<vector<int>>& curr, int i, int j, int m, int n) {
        int liveNeighbours = 0;
        if(i>0) {
            //check the upper neighbour
            if(curr[i-1][j] == 1) liveNeighbours++;
        }
        if(i<m-1) {
            //check the lower neighbour
            if(curr[i+1][j] == 1) liveNeighbours++;
        }
        if(j>0) {
            //check the left neighbour
            if(curr[i][j-1] == 1) liveNeighbours++;
        }
        if(j<n-1) {
            //check the right neighbour
            if(curr[i][j+1] == 1) liveNeighbours++;
        }

        if(i>0 && j>0) {
            if(curr[i-1][j-1] == 1) liveNeighbours++;
        }
        if(i>0 && j<n-1) {
            if(curr[i-1][j+1] == 1) liveNeighbours++;
        }
        if(i<m-1 && j>0) {
            if(curr[i+1][j-1] == 1) liveNeighbours++;
        }
        if(i<m-1 && j<n-1) {
            if(curr[i+1][j+1] == 1) liveNeighbours++;
        }
        return liveNeighbours;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> curr = board;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                int ln = getLiveNeighbours(curr, i, j, m, n);
                if(board[i][j] == 0) {
                    //currently dead
                    //can become alive if has exactly three live neighbours
                    if(ln == 3) {
                        board[i][j] = 1;
                    }
                }
                else if(board[i][j] == 1) {
                    //<2 -> die
                    //==2 || ==3 live
                    //>3 ->die
                    if(ln < 2 || ln > 3) {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
};

*/
// Complexity
// Time: O(mn) as we iterate over the entire board O(mn), checking eight neighbours (O(1)) at each cell.
// Space: O(mn) from the copy that we make, either for storing or modifying.


