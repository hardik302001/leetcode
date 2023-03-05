class Solution {
public:
    int mod = 1000000007;
    int dp[1010][60];
    int recur(int i , int cur , int target , vector<vector<int>>& types , vector<int>temp){
        int n = types.size();
        if(cur>target) return 0;
        if(i==n){
            return (cur==target);
        }

        if(dp[cur][i]!=-1) return dp[cur][i];
        int c = 0;
        c = (c + recur(i+1 , cur  , target , types , temp)%mod)%mod;

        int times = types[i][0];
        int val = types[i][1];
        int x = 1;
        while(x<=times){
            if(cur + val <= target){
                c = (c%mod + recur(i+1 , cur + x*val , target , types, temp)%mod)%mod;
                x++;
            }else{
                break;
            }
        }
        return dp[cur][i] = c%mod; 
    }

    int waysToReachTarget(int t, vector<vector<int>>& types) {
        memset(dp ,-1 , sizeof(dp));
        vector<int>temp;
        return recur(0 , 0 , t , types , temp);
    }
};