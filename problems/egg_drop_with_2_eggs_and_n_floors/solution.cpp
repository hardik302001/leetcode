// binary search wont work , bcz only 2 choices

// DP , TC = O(n^2)

class Solution {
public:
    
    int dp[1001][1001];    
    int recur(int lo , int hi){
        if(lo>=hi) return 0;
        
        if(dp[lo][hi]!=-1) return dp[lo][hi];
        int ans = INT_MAX;
        for(int floorId = lo+1; floorId<=hi ; floorId++){
            
            // +1 bcz we do one move for current floor, and rest part for future moves
            int movesIfFirstEggBreaks = 1 + (floorId-lo-1);
            int movesIfFirstEggDontBreaks = 1 + recur(floorId, hi);
            
            ans = min(ans , max(movesIfFirstEggBreaks , movesIfFirstEggDontBreaks));
        }
        return dp[lo][hi] = ans;
    }
    
    
    int twoEggDrop(int n) {
        if(n==1) return 1;
        memset(dp , -1 , sizeof dp);
        return recur(0 , n);
    }
};