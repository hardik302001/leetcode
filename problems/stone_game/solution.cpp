// dp soln
// exactly same as : https://leetcode.com/problems/predict-the-winner/submissions/


class Solution {
public:
    int dp[1005][1005];
    
    int f(int l, int r, vector <int> &piles) {
        if(l>r) return 0;
        if(l==r) return piles[l];
        if(dp[l][r] != -1) return dp[l][r];
        
        // min for alice bcz we are solving from alice pov,
        // bob will take maximum ,alice will be left with minimum
        int ifleft = piles[l] + min(f(l+2, r, piles), f(l+1, r-1, piles)); // consider both choice for bob
        int ifright = piles[r] + min(f(l+1, r-1, piles), f(l, r-2, piles));
        
        return dp[l][r] = max(ifleft, ifright);
    }
    bool stoneGame(vector<int>& piles) {
        int l = 0, r = piles.size()-1;
        memset(dp, -1, sizeof(dp));
        int alex = f(l, r, piles);
        int sum = 0;
        for(int i=0;i<piles.size();i++) sum += piles[i];

        return alex > (sum - alex);
    }
};


// also seee: this way to code solution : https://leetcode.com/problems/stone-game/discuss/346757/C%2B%2B-Minimax-or-Game-theory-or-Stone-Game


/*
Alice clearly always wins the 2 pile game. With some effort, we can see that she always wins the 4 pile game.

If Alice takes the first pile initially, she can always take the third pile. If she takes the fourth pile initially, she can always take the second pile. At least one of first + third, second + fourth is larger, so she can always win.

so alice always win..


*/