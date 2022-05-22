// credits : https://www.youtube.com/watch?v=i05Ju7AftcM
// take u forward => https://takeuforward.org/data-structure/n-queen-problem-return-all-distinct-solutions-to-the-n-queens-puzzle/
// better see yt video

/*

Time Complexity: O(N^3), row *coln *(3*checking safe) 

Space Complexity: O(N^2)

*/
// class Solution {
// public:

//    	// check if any prev queen is attacking our queen or not 
//    	// only check 3 directions 
//     /*
//             \
//              \
//               \
//         - - -"Q"
//               /
//              /
//             /
//     */

//     bool isSafe1(int row, int col, vector<string> board, int n) {
//      	// upper diag
//       int duprow = row;
//       int dupcol = col;

//       while (row >= 0 && col >= 0) {
//         if (board[row][col] == 'Q')
//           return false;
//         row--;
//         col--;
//       }

//      	// current row 
//       col = dupcol;
//       row = duprow;
//       while (col >= 0) {
//         if (board[row][col] == 'Q')
//           return false;
//         col--;
//       }

//      	// lower diagonal
//       row = duprow;
//       col = dupcol;
//       while (row < n && col >= 0) {
//         if (board[row][col] == 'Q')
//           return false;
//         row++;
//         col--;
//       }
//       return true;
//     }

//    	// go every column to column, and fill 'Q' in all valid rows for that colmn and backtrack accordingly.

//     void solve(int col, vector<string> &board, vector<vector < string>> &ans, int n) {
//       if (col == n) {    	// if we reached after the last coln, then add to answer
//         ans.push_back(board);
//         return;
//       }
//      	// for current coln, check in which of the rows we can place our queen
//       for (int row = 0; row < n; row++) {
//         if (isSafe1(row, col, board, n)) { 
//           board[row][col] = 'Q';
//           solve(col + 1, board, ans, n);
//           board[row][col] = '.';
//         }
//       }
//     }

//     vector<vector < string>> solveNQueens(int n) {
//       vector<vector < string>> ans;
//       vector<string> board(n);
//       string s(n, '.');
//       for (int i = 0; i < n; i++) {
//         board[i] = s;
//       }
//       solve(0, board, ans, n);
//       return ans;
//     }
// };

//-----------------------------------------------------------------------------------

// approach 2, optimising isSafe function, dec TC, and inc SC

/*

Time Complexity: O(N^2), row *coln *(3*O(1)) 

Space Complexity: O(N^2) + 3*O(n)

*/

class Solution
{
    public:
        void solve(int col, vector<string> &board, vector<vector< string >> &ans, vector< int > &leftrow, vector< int > &upperDiagonal, vector< int > &lowerDiagonal, int n)
        {
            if (col == n)
            {
                ans.push_back(board);
                return;
            }
            
            for (int row = 0; row < n; row++)
            {
                if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) // non attacked
                {
                    board[row][col] = 'Q';
                    
                    leftrow[row] = 1;                     // for current row
                    lowerDiagonal[row + col] = 1;         // for prinicipal diagonal , we know its i+j
                    upperDiagonal[n - 1 + col - row] = 1; // for non principal diafonal its ( (n-1) + (j-i) ) , rememeber it "col-row + (n-1)""
                    
                    solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
                    
                    board[row][col] = '.';
                    
                    leftrow[row] = 0;
                    lowerDiagonal[row + col] = 0;
                    upperDiagonal[n - 1 + col - row] = 0;
                    
                    // we need to backtrack our checks vector also , 
                }
            }
        }

    vector<vector < string>> solveNQueens(int n)
    {
        vector<vector < string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        vector<int> leftrow(n, 0), upperDiagonal(2 *n - 1, 0), lowerDiagonal(2 *n - 1, 0);	// for O(1) checking

        solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};