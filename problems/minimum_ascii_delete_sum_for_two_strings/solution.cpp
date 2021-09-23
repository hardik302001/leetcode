//same as lcs


class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int dp[1001][1001] = {0};
        //sum of ascii of both strings
        int n1 = accumulate(s1.begin(), s1.end(), 0);
        int n2 = accumulate(s2.begin(), s2.end(), 0);
        
        
        for ( int i = 0; i < s1.size(); ++i ) {
            for ( int j = 0; j < s2.size(); ++j ) {
                if ( s1[i] == s2[j] ) {
                    dp[i+1][j+1] = dp[i][j] + int(s1[i]) * 2;       //bcz we need to subtract this from (n1 + n2), so lcs is common in both strings, so twice will be removed
                    
                    //here we dont need length, but we need the ascii sum 
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        // dp[m][n] gives sum of lcs 
        

        return n1 + n2 - dp[s1.size()][s2.size()];
    }
};