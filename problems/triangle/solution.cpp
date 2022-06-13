
// https://leetcode.com/problems/triangle/discuss/1721645/Recursion-or-Memoization-or-Tabulation-or-Space-Optimized-C%2B%2B



class Solution {
public:
    int triangledp(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=triangle.size())
            return 0;
        if(i==triangle.size()-1)
            return dp[i][j] = triangle[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j] = triangle[i][j] + min(triangledp(triangle,i+1,j,dp),triangledp(triangle,i+1,j+1,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),-1));
        return triangledp(triangle,0,0,dp);
    }
};