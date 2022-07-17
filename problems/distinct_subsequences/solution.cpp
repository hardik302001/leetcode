/*
We check recusively for each character in t whether it matches with our source string s's current index in which we are standing. If yes, we have two choices, whether to include in our possible string or leave it and check the remaining characters in s. We compute this until we run out of characters to match, i.e our t is empty, in which case we have 1 valid sequence. If we run out of characters in s, we have an invalid/incomplete sequence.
*/
class Solution {

    int dp[1001][1001];

public:

    int solve(string& s1,string& s2,int n,int m){

        if(m<0){

            return 1;           // sequence found

        }

        if(n<0){

            return 0;           // sequence source exhausted

        }

        if(dp[n][m]!=-1){

            return dp[n][m];

        }

        if(s1[n]==s2[m]){

            // i have 2 choices

            return dp[n][m]=solve(s1,s2,n-1,m-1)+solve(s1,s2,n-1,m);

        }else{

            return dp[n][m]=solve(s1,s2,n-1,m);     // check previous character at source to compare

        }

    }

    

    int numDistinct(string s1, string s2) {

        memset(dp,-1,sizeof dp);

        return solve(s1,s2,s1.size()-1,s2.size()-1);

    }

};
        

