// just count ship heads

class Solution {
public:
    int countBattleships(vector<vector<char>>& board)
    {
        if(board.empty() || board.front().empty()) return 0;

        int rowCount = board.size();
        int colCount = board.front().size();

        int count = 0;
        for(int y = 0; y < rowCount; y++) {
            for(int x = 0; x < colCount; x++) {
                if(board[y][x] == 'X') {
                    if(y > 0 && board[y - 1][x] == 'X') continue;
                    if(x > 0 && board[y][x - 1] == 'X') continue;
                    ++count;
                }
            }
        }
        return count;
    }
};