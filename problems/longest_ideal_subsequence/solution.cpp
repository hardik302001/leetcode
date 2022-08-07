// you cant do on the basis of indexing, 2d dp with 10power5. It wont work.

// ----------------------------------------------------------------------------

// we used ind of prev(ascii)
// prev = vertical bar ('|'), bcz it is next to 'z'


class Solution {
public:
    int dp[100001][30];
    int solve(int i , char p , string &s , int k){
        int n = s.size();
        if(i==n) return 0;
        if(dp[i][p-'a']!=-1) return dp[i][p-'a'];
        
        int not_inc = solve(i+1, p , s, k);
        int inc = 0;
        if(p=='|' or abs(s[i]-p)<=k){
            inc = 1 + solve(i+1, s[i] , s, k);
        }
        
        return dp[i][p-'a'] = max(inc, not_inc);
    }
    
    int longestIdealString(string s, int k) {
        int n = s.size();
        memset(dp, -1 , sizeof dp);
        return solve(0, '|' , s, k);
    }
};