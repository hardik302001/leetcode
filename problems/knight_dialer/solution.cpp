class Solution {
public:
    long long int dp[4][3][5001];
    vector<pair<int, int>>dirs = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}};
    long long int knightDialer(int n) {
        
        for(int i = 0;i<4;i++){
            for(int j = 0;j<3;j++){
                for(int k = 0;k<5001;k++){
                    dp[i][j][k] = -1;
                }     
            }
        }    
        
        long long int ans = 0;
        for(int i = 0; i<4;i++){
            for(int j = 0;j<3;j++){
                ans = ans + recur(i, j , n)%1000000007;   
            }
        }
        
        return ans%1000000007;
    }
    
    long long int recur(int i , int j , int n){
        if(i<0 or j<0 or i>=4 or j>=3 or (i==3 and j!=1)){
            return 0;
        }
        if(dp[i][j][n]!=-1){
            return dp[i][j][n];
        }
        if(n==1){
            return (dp[i][j][n] = 1);
        }
        
        long long int res = 0;
        for(auto [x, y]: dirs){
            res = res + recur(i + x, j + y , n-1)%1000000007; 
        }   
        return (dp[i][j][n] = res%1000000007);
    }
    
};