

class Solution {
public:
    int dp[1001];
    int recur(int i , vector<int>&cost){
        int n = cost.size();    
        if(i>=n){
            return 0;
        }
    
        if(dp[i]!=-1) return dp[i];
        int one = cost[i] + recur(i+1, cost);
        int two = cost[i] + recur(i+2, cost);
        return dp[i] = min(one, two);
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp , -1 , sizeof dp);
        return min(recur(0 , cost), recur(1, cost));    
    }
};






















 //-----------------------------------------------------------------------



/*

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        vector<int>dp(n+1,0);
        dp[0] = 0;
        dp[1] = 0;
        
        for(int i = 2;i<=(n);i++){
            dp[i] = min(dp[i-1] + cost[i-1],dp[i-2]+ cost[i-2]);
        }
        
        return dp[n];
    }
};

*/