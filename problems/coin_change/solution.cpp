//minimizing coin cses


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        long long int INF = 10000000000;
        vector < long long > dp(amount +1,INF);
        dp[0] = 0;

        for(int i = 1;i<=amount;i++){
            long long int ans = INF;
            for(int j = 0;j < coins.size();j++){
                if(coins[j]<=i){
                    ans = min(ans, dp[i-coins[j]]);
                }
            }

            if(ans==INF){
                dp[i] = INF;
            }
            else{
                dp[i] = ans +1;
            }
        }

        if(dp[amount]==INF){
            return -1;
        }
        else{
            return dp[amount];
        }
    }
};

