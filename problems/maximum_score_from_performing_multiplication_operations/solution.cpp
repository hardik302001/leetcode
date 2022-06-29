// recursion : - Tle (O(2^n))
/*
class Solution {
public:

    int solve(int l , int r , vector<int>&nums , vector<int>&mul ,int n , int m, int op ){
        if(l>r or op==m) return 0;
        if(l==r) return mul[op]*nums[l];
        
        int ans = INT_MIN;
        
        ans = max(ans , nums[l]*mul[op] + solve(l+1 , r , nums , mul , n , m , op+1));
        ans = max(ans , nums[r]*mul[op] + solve(l , r-1 , nums, mul , n , m , op+1));

        return ans;
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int m = mul.size();
        int n = nums.size();
        int l = 0;
        int r = n-1;
        return solve(l , r , nums , mul , n ,m ,0);
        
    }
};
*/

// DP
// from 3 state to 2 state

// use vis as memoising array
// use dp to store meoised values

class Solution {
public:
    int dp[1001][1001];   // l and op both can go upto power 3
    bool vis[1001][1001];
    int solve(int l , vector<int>&nums , vector<int>&mul ,int n , int m, int op ){
        int r = n-1 - (op -l);
        if(l>r or op==m) return 0;
        if(l==r) return mul[op]*nums[l];
        
        if(vis[l][op]) return dp[l][op];  /////////////////////////////////// and here
        
        int ans = INT_MIN;
        
        ans = max(ans , nums[l]*mul[op] + solve(l+1 , nums , mul , n , m , op+1));
        ans = max(ans , nums[r]*mul[op] + solve(l , nums, mul , n , m , op+1));
        vis[l][op] = true;
        return dp[l][op] = ans;
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int m = mul.size();
        int n = nums.size();
        int l = 0;
        int r = n-1;
        memset(dp , 0 , sizeof dp); 
        memset(vis , false , sizeof vis);
        return solve(l  , nums , mul , n ,m ,0);
        
    }
};