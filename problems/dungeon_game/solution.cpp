// IDEA:  https://leetcode.com/problems/dungeon-game/discuss/698376/C%2B%2B-or-Beginner-friendly-dp-%2B-Explanation-and-idea
// similar prob : https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();   // no of rows
        if(r == 0) return 0; // if empty then return 0
        int c = dungeon[0].size();  // no of columns
		// DP with r+1 x c+1 dimension and all values initialized to INT_MAX
        vector<vector<int>>dp(r+1,vector<int>(c+1,INT_MAX));
		// Initializing the cell to the bottom and right of princess' cell with value 1.
        dp[r-1][c] = 1;
        dp[r][c-1] = 1;
		
        //terating over dp excluding the additional row and column we added.
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                int val = min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j];  // value is minimum health to land on next - health need to stay
                dp[i][j] = max(1,val); // most impo line!!...minimum value required is 1. maximum is the +ve value we calculated.
            }
        }
        
        return dp[0][0];  // The first element contains the minimum health needed to rescue the princess.
    }
};

