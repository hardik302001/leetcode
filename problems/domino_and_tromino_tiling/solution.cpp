// courtesy : https://www.youtube.com/watch?v=aVIFpdAg33U
// considering the duplicate cases are the most important thing in this question!

class Solution {
public:
    int numTilings(int n) {
        vector<int> dp (n+1,0);
        dp[0] = 0;
        if(n==0){return dp[n];}
        dp[1] = 1;
        if(n==1){return dp[n];}
        dp[2] = 2;
        if(n==2){return dp[n];}
        dp[3] = 5;
        if(n==3){return dp[n];}
        
        for(int i = 4;i<=n;i++){
            dp[i] = 2*dp[i-1]%1000000007 + dp[i-3]%1000000007;
            dp[i] = dp[i]%1000000007;
        }
        // for(int i = 0;i<dp.size();i++){
        //     cout<<i<<" " << dp[i]<<endl;
        // }
        return dp[n];
    }
};