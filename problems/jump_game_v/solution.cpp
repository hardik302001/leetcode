// similar code and idea as: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

// memosised dp O(n2)

class Solution {
public:
    
    vector<int>dp = vector<int>(1001,-1);
    int recur(vector<int>&arr , int d, int i){
        int n = arr.size();
        int ans = 1;
        if(dp[i]!=-1){
            return dp[i];
        }
        
        //right
        for(int j = i+1;j<=min(i+d, n-1);j++){
            if(arr[i]>arr[j]){
                ans = max(ans , 1 + recur(arr, d, j));
            }else{
                break;    //, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j 
            }
        }
        //left
        for(int j = i-1;j>=max(i-d, 0);j--){
            if(arr[i]>arr[j]){
                ans = max(ans , 1 + recur(arr, d, j));
            }else{
                break;   //  , you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j 
            } 
        }
        
        return (dp[i] = ans);
    }
    
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int res = 1;   // current position where i m standing
        for(int i = 0;i<n;i++){   // start from any index
            res = max(res, recur(arr, d , i));
        }
        
        return res;
    }
};