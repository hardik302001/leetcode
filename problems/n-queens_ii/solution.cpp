class Solution
{
    public:
        void solve(int col, vector<string> &board, int &ans, vector< int > &leftrow, vector< int > &upperDiagonal, vector< int > &lowerDiagonal, int n)
        {
            if (col == n)
            {
                ans++;
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

    int totalNQueens(int n)
    {
        int ans = 0;
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



