// no of partitions needed for string(i:n)

class Solution {
public:
    int dp[2001];
    int recur(int start , int n , string &s){
        if(start==n) return 0;
        if(dp[start]!=-1) return dp[start];
        
        int mi = INT_MAX;        
        for (int i = start; i < n; i++) {
            if (isPalindrome(s, start, i)) { 
                mi = min(mi , 1 + recur(i+1, n, s));
            }
        }
        
        return dp[start] = mi;    
    }
    
    
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    
    int minCut(string s) {
        int n = s.size();
        memset(dp , -1 , sizeof dp);
        return recur(0 , n, s)-1;
    }
};