
// maybe somehwat similar ques: https://www.codingninjas.com/codestudio/library/building-bridges
// soution :  https://www.youtube.com/watch?v=w6tSmS86C4w&t=518s


// -----------------------------------------------------------------

// lcs

class Solution {
public:
    
    int longestCommonSubsequence(vector<int>& x, vector<int>& y) {
        int n=x.size(),m=y.size();
        string s;
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=m;i++)dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
    
        return dp[n][m];
    }
    
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int ans = longestCommonSubsequence(nums1, nums2);
        return ans;
        
    }
};