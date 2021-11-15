//similar to :  https://leetcode.com/problems/longest-increasing-subsequence/

// https://leetcode.com/problems/largest-divisible-subset/discuss/1578685/C%2B%2B-EASY-Solution-oror-Standard-LIS-Variation-oror-INTUITIVE-approach


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>prev(n, -1); //previous index array to track for previous element in the dp before i
        int end = 0;   //bcz if only one ;eement, we cam consider anyways
        int m = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i]%nums[j]==0 and dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                }
                
            }
            
            
            if(dp[i]>m){        // we cant update m, anytime.. we need to update m to the max of dp vector
                end = i;
                m = dp[i];
            }
        }
        
        
        vector<int>ans;
        while(end!=-1){
            ans.push_back(nums[end]);
            end = prev[end];
        }
        
        return ans;
    }
};