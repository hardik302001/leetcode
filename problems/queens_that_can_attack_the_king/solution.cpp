class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> result;
        bool seen[8][8] = {};
        for (vector<int> queen : queens) seen[queen[0]][queen[1]] = true;

        for (int dr = -1; dr <= 1; dr++) { // find the nearest queen can attack king by 8 directions
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) continue; // exclude center
                vector<int> queen = findNearestQueenCanAttackKing(seen, king, dr, dc);
                if (queen.size() > 0) result.push_back(queen);  // only one queen as output
            }
        }
        return result;
    }
    
    vector<int> findNearestQueenCanAttackKing(bool seen[8][8], vector<int>& king, int dr, int dc) {
        int r = king[0] + dr, c = king[1] + dc;
        while (r >= 0 && c >= 0 && r < 8 && c < 8) {
            if (seen[r][c]) return vector<int>{r, c};
            r += dr;
            c += dc;
        }
        return vector<int>{};
    }
};
