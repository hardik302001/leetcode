// top dowm 
//  O(n^1.5)


class Solution {
public:
    int dp[100001];
    int solve(int n){  // int , bcz so we have 3 state fr dp => -1(uninitialised) , 0(false)  , 1(true)
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        
        int ans = 0;
        
        for(int i = 1;i*i<=n;i++){
            if(solve(n-(i*i))==0){  // bob should loose
                ans = 1; 
                break;
            }
        }
        
        return dp[n] = ans;
    }
    
    bool winnerSquareGame(int n) {
        memset(dp , -1 , sizeof dp);
        bool res = solve(n);
        return res;
    }
};