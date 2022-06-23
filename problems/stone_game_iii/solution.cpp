// DP

// we focus on alice and predict what all things bob can do!
// code very similar to : lc stone game 


class Solution {
public:
    
    int dp[50005];
    
    int solve(vector<int>&s, int ind ){
        int n = s.size();
        if(ind>=n) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int sum = 0;
        int res = INT_MIN;
        for(int i = ind;i<ind+3 and i<n ; i++){
            sum+= s[i];
            res = max( res , sum + min({solve(s, i+2) , solve(s, i+3 ) , solve( s , i+4)}));
            // min of vector
        }
        
        return dp[ind] = res;
    }
    
    string stoneGameIII(vector<int>& s) {
        int n = s.size();
        memset(dp , -1, sizeof dp);
        int al = solve(s , 0);
        int bob = accumulate(s.begin(), s.end() , 0) - al;
        if(al>bob) return "Alice";
        else if (al<bob) return "Bob";
        return "Tie";
    }
};