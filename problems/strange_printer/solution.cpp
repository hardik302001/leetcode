// idea : https://leetcode.com/problems/remove-boxes/submissions/
// do that first , then come here

class Solution {
public:
    
    int dp[101][101];   // l , r 
    
    // l, r included
    int recur(int l , int r , string& s){
        if(l>r) return 0;  
        if(dp[l][r]!=-1) return dp[l][r];
        
        while(l+1<=r and s[l]==s[l+1]){
            l+=1;
        } 
        
        // individually doing each continuous subarray with equal elements
        int ans = recur(l+1, r, s) + 1;
       
        for(int i = l+1;i<=r;i++){
            if(s[l]==s[i]){ // consider all occurence of breakings
                int middle =  recur(l+1, i-1, s);
                int nextPartition = recur(i, r, s);  
                
                ans = min(ans , middle + nextPartition);       
            }
        }
        
        return dp[l][r] = ans;
        
    }
    int strangePrinter(string s) {
        int n = s.size();
        memset(dp , - 1, sizeof dp);
        return recur(0, n-1, s);
    }
};


