// https://cses.fi/problemset/task/1636
//coin combinations 2 = swap loops frpm coin comb 1
// dice combination and coin combination 1 are exactly same...

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1,0);
        dp[0] = 1;
        
        // we do coin array above and amount below to get ordered count...
        // if we do its reverse then we would consider all cases...

        for(int i = 0; i<coins.size(); i++){            
            for(int j = coins[i]; j<= amount; j++){
                dp[j] = dp[j] + dp[j - coins[i]];   // exclude + include (both cases)
            }
        }
        return dp[amount];
    }
  
};



//----------------------------------------------------------------


// for more info : https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=2

// top down
/*
    Time Complexity: O(N * V)
    Space Complexity: O(N * V)
    
    where N is the length of denominations array and V is the value.
*/

/*

long countWaysToMakeChangeHelper(int denominations[], int value, int n, vector<vector<long>> &memo) 
{
    // if total is 0, return 1 (solution found)
    if (value == 0) 
    {
        return 1;
    }

    // return 0 (solution do not exist) if total become negative or
    // no elements are left
    if (n < 0 || value < 0) 
    {
        return 0;
    }

    if (memo[value][n] != -1)
    {
        return memo[value][n];
    }
    // Case 1. include current coin S[n] in solution and recur
    // with remaining change (N - S[n]) with same number of coins
    // dont dec index
    long incl = countWaysToMakeChangeHelper(denominations, value - denominations[n], n, memo);

    // Case 2. exclude current coin S[n] from solution and recur
    // for remaining coins (n - 1)
    long excl = countWaysToMakeChangeHelper(denominations, value, n - 1, memo);

    // return total ways by including or excluding current coin
    memo[value][n] = incl + excl;
    
    return memo[value][n];
}

long countWaysToMakeChange(int denominations[], int n, int value) 
{
    vector<vector<long>> memo(value + 1, vector<long>(n + 1, -1));
    return countWaysToMakeChangeHelper(denominations, value, n - 1, memo);
}

*/