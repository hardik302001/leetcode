// also try doing bottom up 
// also see bfs : https://leetcode.com/problems/interleaving-string/discuss/31948/8ms-C++-solution-using-BFS-with-explanation/276068

// also see: https://leetcode.com/problems/interleaving-string/discuss/1247165/C%2B%2B-Memoizn(3-variables)-greater-Memoizn(without-3rd-var)-greater-DP-(m*n)-greater-DP(n)



// BLIND RECURSION 
// check all possiblities
/*
class Solution {
public:
    bool recur(string s1, string s2, string s3, int i, int j, int k){
        if(i==s1.size() and j==s2.size() and k==s3.size()) return true;
        
        bool ans = false;
        if(i < s1.size() and s3[k]==s1[i]) ans|=recur(s1 ,s2, s3, i+1, j , k+1);
        if(j < s2.size() and s3[k]==s2[j]) ans|=recur(s1 ,s2, s3, i, j+1 , k+1);
        return ans;
    }    

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size()!=s3.size()) return false;
        return recur(s1, s2, s3, 0, 0, 0);
        
    }
};
*/


/*
// recursive memoised

class Solution {
public:
    int dp[101][101][201];
    bool recur(string s1, string s2, string s3, int i, int j, int k){
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(i==s1.size() and j==s2.size() and k==s3.size()) return true;
        
        bool ans = false;
        if(i < s1.size() and s3[k]==s1[i]) ans|=recur(s1 ,s2, s3, i+1, j , k+1);
        if(j < s2.size() and s3[k]==s2[j]) ans|=recur(s1 ,s2, s3, i, j+1 , k+1);
        return dp[i][j][k] = ans;
    }    

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size()!=s3.size()) return false;
        memset(dp , -1 , sizeof dp);
        return recur(s1, s2, s3, 0, 0, 0);
        
    }
};

*/



// remove 3rd state bcz we are doing k+1 always 
// bcz at any time k = i+j
class Solution {
public:
    int dp[101][101];
    bool recur(string s1, string s2, string s3, int i, int j, int k){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==s1.size() and j==s2.size() and k==s3.size()) return true;
        
        bool ans = false;
        if(i < s1.size() and s3[k]==s1[i]) ans|=recur(s1 ,s2, s3, i+1, j , k+1);
        if(j < s2.size() and s3[k]==s2[j]) ans|=recur(s1 ,s2, s3, i, j+1 , k+1);
        return dp[i][j] = ans;
    }    

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size()!=s3.size()) return false;
        memset(dp , -1 , sizeof dp);
        return recur(s1, s2, s3, 0, 0, 0);
        
    }
};