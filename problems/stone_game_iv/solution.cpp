class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1 , false);
        dp[1] = true;
        for(int i = 1;i<=n;i++){
            bool possible = false;
            for(int j = 1;j*j<=i;j++){
                if (i==j*j){
                    dp[i] = true;
                }
                if(dp[i-j*j]==false){
                    possible = true;
                }
            }
            if(possible){
                dp[i] = true;
            }
            
        }
        
   
        return dp[n];
    }
};