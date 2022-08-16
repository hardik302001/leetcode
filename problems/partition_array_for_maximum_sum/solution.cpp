class Solution {
public:
    int dp[501];
    int recur(int start , vector<int>&arr, int k){
        if(start==arr.size()) return 0;
        if(dp[start]!=-1) return dp[start];
        
        int ans = INT_MIN;
        int ma = INT_MIN;
        int len = 0;
        for(int i = start ; i<min(int(arr.size()) ,start+k ); i++){
            len++;
            ma = max( ma, arr[i]);
            int res = len*ma + recur(i+1, arr, k);
            ans = max(ans , res);
        }
        return dp[start] = ans;
        
    }
    
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp , -1 , sizeof dp);
        return recur(0 , arr, k);  // max sum frm arr(i:n)
    }
};