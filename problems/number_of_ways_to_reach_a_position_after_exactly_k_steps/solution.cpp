class Solution {
public:
    int mod = 1000000007;
    int dp[3001][1001];
    
    int recur(int s, int e, int k){
        if(k==0){
            if (s==e) return 1;
            else      return 0;
        }

        if(k<0) return 0;
        
        if(dp[s+1000][k]!=-1) return dp[s+1000][k];
        
        int x = recur(s+1, e, k-1);
        int y = recur(s-1, e, k-1);
        return dp[s+1000][k] = (x%mod + y%mod)%mod;
    
    }
    
    int numberOfWays(int s, int e, int k) {
        memset(dp , -1, sizeof dp);
        int x = recur(s, e, k);
        return x%mod;
    }
};