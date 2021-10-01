//same as lcs https://leetcode.com/problems/longest-common-subsequence/


class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector< vector< int> > dp(1001, vector<int>(1001,0));   // (0 to m (m+1)), (0 to n (n+1))
        //sum of ascii of both strings
        int n1 = accumulate(s1.begin(), s1.end(), 0);
        int n2 = accumulate(s2.begin(), s2.end(), 0);
        
        for ( int i = 1; i <= s1.size(); ++i ) {
            for ( int j = 1; j <= s2.size(); ++j ) {
                if ( s1[i-1] == s2[j-1] ) {
                    dp[i][j] = dp[i-1][j-1] + 2 * int(s1[i-1]);    //
                    
                    //here we dont need length, but we need the ascii sum 
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        // dp[m][n] gives sum of lcs 
        

        return n1 + n2 - dp[s1.size()][s2.size()];  
    }
};