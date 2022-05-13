//https://cses.fi/problemset/task/1636
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
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
  
};