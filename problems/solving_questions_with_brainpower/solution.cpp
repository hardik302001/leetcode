class Solution {
public:
    vector<long long int>dp = vector<long long int>(100001, LONG_MIN);
    long long recur(vector<vector<int>>& q, int i, int n){
        if(i==(n-1)){
            return q[i][0];
        }
        if (i>n-1){
            return 0;
        }
        
        if(dp[i]!=LONG_MIN){
            return dp[i];
        }
        
        long long int ans;
        long long int get = recur(q, i+q[i][1]+1, n) + q[i][0];
        long long int ignore = recur(q, i + 1, n);
        ans = max( get,ignore );
        // cout<<get <<" "<< ignore <<endl;
        return (dp[i] = ans);
    }
    
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        return recur(q , 0, n);
    }
};