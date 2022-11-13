class Solution {
public:
    int dp[2005];
    bool pal[2005][2005];

    
    int recur(int i , int n , string &s , int k){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = 0;
    
        for(int x = i;x<n;x++){
            int check = pal[i][x];
            if((x-i+1>=k)){
                if(check){
                    ans = max(ans , 1 + recur(x+1 , n , s, k));
                }
                else{
                    ans = max(ans , recur(x+1 , n , s, k));
                }
            }else{
                ans = max(ans , recur(x+1 , n , s, k));
            }
        } 
        
        return dp[i] = ans;
    }
    
    int maxPalindromes(string s, int k) {
        int n = s.size();
        memset(dp , -1 , sizeof dp);
        
        
        // Creates DP array with s[i -> j] true if palindrome, else false
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){             
                pal[i][j] = false;
            }
        }
        
        // memoise with length , bcz it shud be bottom up
        for(int len=1; len <= n; len++){
            for(int i=0; i <= n-len; i++){
                int j = i+len-1;
                pal[i][j] = (len <= 2 ? true : pal[i+1][j-1]) && s[i] == s[j];
            }
        }
        return recur(0 , n , s , k);
    }
};