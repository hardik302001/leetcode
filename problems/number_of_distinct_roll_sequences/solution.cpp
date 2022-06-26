class Solution {
public:
    vector<int> arr{1,2,3,4,5,6};
    int m = 1000000007;
    int dp[10001][7][7];
    long solve(int n, int last, int prevLast, int i) {
        if(i == n) return 1;
        if(dp[i][last][prevLast]!=-1) return dp[i][last][prevLast];
        
        long res = 0;
        
        for(auto cur:arr) {
			// validate step 1 and 2
            if(cur == last or cur == prevLast or (last!=0 and (__gcd(cur, last)!=1))) continue;
            res+=(solve(n, cur, last, i+1)%m);
        }
        return dp[i][last][prevLast] = res%m;
    }
    
    int distinctSequences(int n) {
        memset(dp , -1 , sizeof dp);
        return solve(n, 0, 0, 0);   
    }
};