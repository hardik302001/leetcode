// 1d dp


class Solution {
public:
    int dp[200005];
    
    int recur(int l , int low , int high , int x , int y){
        if(l>high) return 0;
        if(dp[l]!=-1) return dp[l];
        
        int ans;
        if(l>=low and l<=high) ans = 1;
        else                   ans = 0;
        
        ans += recur(l + x, low , high , x, y)%1000000007;
        ans += recur(l + y , low , high , x, y)%1000000007;
        return dp[l] = (ans)%1000000007;
        
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp , -1 , sizeof dp);
        return recur(0 , low ,high , zero , one);
    }
};