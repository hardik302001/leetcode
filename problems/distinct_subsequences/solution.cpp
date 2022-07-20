// also see: https://leetcode.com/problems/distinct-subsequences-ii/
// https://leetcode.com/discuss/interview-question/algorithms/124943/number-of-distinct-subsequences


class Solution {
public:
    int dp[1001][1001];
    int recur(int i , int j , string &s, string &t){
        if(j>=t.size()){  // it means we have traversed full string t completely.
            return 1;
        }
        if(i>=s.size()){
            return 0;
        }
  
        if (dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(s[i]!=t[j]) ans =  recur(i+1, j , s, t); 
        else           ans = recur(i+1, j , s, t) + recur(i+1, j+1 ,s , t); 
        
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof dp);
        return recur(0 ,0, s, t);
    }
};