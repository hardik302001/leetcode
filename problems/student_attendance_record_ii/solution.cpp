class Solution
{
    public:
    int dp[100001][2][3];
    int mod = 1e9 + 7;
    int sz;
    long long int solve(int ind, int a, int l)
    {
        
        if(a>=2 or l>=3) return 0;
        if(ind==sz) return 1;

        if (dp[ind][a][l] != -1)
            return dp[ind][a][l];

        long long ans = ( solve(ind+1, a, 0) % mod + solve(ind+1, a + 1, 0) % mod + solve(ind+1, a, l + 1) % mod) % mod;
       	                     // present                     	// absent                     	// late      

        return dp[ind][a][l] = ans;
    }

    int checkRecord(int n)
    {
        sz = n;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};