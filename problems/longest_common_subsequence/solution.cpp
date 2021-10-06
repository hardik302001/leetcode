//see how to print string, you cant directly push characrter into string, like we did in last soln, that is wrong!
//also see https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
// O(mn) time and space
class Solution {
public:
    int longestCommonSubsequence(string x, string y) {
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
        
        //ADITYA VERMA DP , PRINTING LCS
        
        //it only gives one of lcs, more than one lcs are possible
        // for printing longest common subsequence
        int i=n,j=m;
        while(i>0 && j>0){    // if any of this i and j becomes 0 means one string is empty 
            if(x[i-1]==y[j-1]){
                s+=x[i-1];    //if character matches then add that to result string and move diagonally up
                i--;j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j])j--;    // else find the max of up and right position of dp table and move accordingly to up or left
                else i--;
            }
        }
        reverse (s.begin(),s.end());    // reverse the string as we started from last
        cout<<s;
        return dp[n][m];
    }
};