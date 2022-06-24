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


// idk why but top down gives TLE on 62/63
/*
class Solution {
public:
    int dp[1001][1001];   // l and op both can go upto power 3
    int solve(int l , vector<int>&nums , vector<int>&mul ,int n , int m, int op ){
        int r = n-1 - (op -l);
        if(l>r or op==m) return 0;
        if(l==r) return mul[op]*nums[l];
        
        if(dp[l][op]!=-1) return dp[l][op];
        
        int ans = INT_MIN;
        
        ans = max(ans , nums[l]*mul[op] + solve(l+1 , nums , mul , n , m , op+1));
        ans = max(ans , nums[r]*mul[op] + solve(l , nums, mul , n , m , op+1));

        return dp[l][op] = ans;
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int m = mul.size();
        int n = nums.size();
        int l = 0;
        int r = n-1;
        memset(dp , -1 , sizeof dp);
        return solve(l  , nums , mul , n ,m ,0);
        
    }
};

*/


// that why i did bottom up
class Solution {
public:
    int maximumScore(vector<int>& v, vector<int>& m) {
        
        vector<vector<int>> dp(m.size()+1, vector<int>(m.size()+1));
        for(int i = 0; i < dp.size(); i++){
            dp[i][dp[0].size()-1] = 0;
            dp.back()[i] = 0;
        }
        for(int i = dp.size()-2; i >= 0; i--) {
            for(int j = dp[0].size()-2; j >=0; j--) {
                dp[i][j] = max(m[i]*v[j] + dp[i+1][j+1],
                                    m[i]*v[v.size()-1-(abs(i-j))] + dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};