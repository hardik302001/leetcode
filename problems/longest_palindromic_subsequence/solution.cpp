//THE IDEA ID FROM PEPCODING LPS 41 minutes video:

//PLEASE PLEASE DO WATCH IT!!
//this is standard solution for LPS
//well I have 2 more solutions for it.. see previous submissions too

//Recursvie based solution is easy to understand and visualise

//lcs based solution is dirrect and easy to see why it works: LPS(s) = LCS(s, rev(S))



//TC = N2 , SC = N2
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size=s.size();
        if(size==1){
            return 1;
        }
       //dp[i:j] gives lps for substring s[i:j]
        vector<vector<int>> dp(size,vector<int>(size));
        //GAP METHOD
        for(int gap=0;gap<size;gap++){
            int row = 0;
            for(int col=gap;col<size;col++){
                if(gap==0){
                    dp[row][col]=1;
                }
                else if(gap==1){
                    dp[row][col]= (s[row]==s[col]) ? 2 : 1;
                }
                else{
                    if(s[row]==s[col]){
                        dp[row][col]=2+dp[row+1][col-1];
                    }
                    else{
                        //prefix and suffix
                        dp[row][col]=max(dp[row][col-1],dp[row+1][col]);
                    }
                }
                
                row++;
            }
        }
        return dp[0][size-1];
    }
};