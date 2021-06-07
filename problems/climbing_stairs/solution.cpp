class Solution {
public:
    
    
    int climbStairs(int n) {
        vector<int>dp(50);

        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i<n+1;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};