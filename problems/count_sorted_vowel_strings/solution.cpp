// RECURSION + DP(2 state, size of cur string and last char of current string )


class Solution {
public:
    int dp[6][51];

    vector<char>vow = {'a', 'e', 'i' , 'o', 'u'};
    int recur(int last , int n){
        if(n==0){
            return 1;
        }
        
        if(dp[last][n]!=-1){
            return dp[last][n];
        }
        
        int ans = 0;
        for(int x = 0;x<vow.size();x++){
            if(vow[x]>=vow[last]){
                ans+= recur(x , n-1);
            }
        }
        
        return dp[last][n] = ans;    
    }
    
    int countVowelStrings(int n) {
        memset(dp , -1, sizeof dp);
        return recur(0,n);
    
    }
};