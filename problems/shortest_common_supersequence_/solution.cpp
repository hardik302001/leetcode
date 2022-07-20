class Solution {
public:
    
    string lcs(string s1, string s2){
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        
        int x = n;
        int y = m;
        string lc = "";
        while(x>0 and y>0){
            if(s1[x-1]==s2[y-1]){
                lc+=s1[x-1];
                x--;
                y--;
            }else{
                if(dp[x-1][y]>dp[x][y-1]){
                    x--;
                }else{
                    y--;
                }
            }
        }
        
    
        reverse(lc.begin(), lc.end());
        return lc;
        
    
    }


    string shortestCommonSupersequence(string s1, string s2) {
        string lc = lcs(s1, s2);
        string ans = "";
        
        
        // well we can do this below part while printing lcs only , bcz we are again moving using pointers only..
        int x = 0;
        int y = 0;
        int z = 0;
        
        
        // 3 pointer and track
        while(z<lc.size()){
            if(s1[x]==lc[z] and s2[y]==lc[z]){
                ans+=lc[z];
                x++;
                y++;
                z++;
            }else if(s1[x]!=lc[z]){
                ans+=s1[x];
                x++;
            }else if(s2[y]!=lc[z]){
                ans+=s2[y];
                y++;
            }
        }
        
        while(x< s1.size()) ans+=s1[x], x++;
        while(y< s2.size()) ans+=s2[y], y++;

        return ans;
    }
};