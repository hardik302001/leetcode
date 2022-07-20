// similar to :  https://leetcode.com/problems/longest-increasing-subsequence/

// https://leetcode.com/problems/largest-divisible-subset/discuss/1578685/C%2B%2B-EASY-Solution-oror-Standard-LIS-Variation-oror-INTUITIVE-approach


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int lastidx = 0;
        int ans = 0;
        vector<int>dp(n+1, 1), hash(n+1, -1);
        for(int i = 0;i<n;i++){
            hash[i] = i;
            for(int j = 0;j<i;j++){
                if(nums[i]%nums[j]==0 and dp[i]<1+dp[j]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(ans<dp[i]){
                ans = max(ans, dp[i]);
                lastidx  = i;                
            }

        }
        
        vector<int>lis;
        while(hash[lastidx]!=lastidx){
            lis.push_back(nums[lastidx]);
            lastidx =  hash[lastidx];
        }
        
        lis.push_back(nums[lastidx]);
        
        reverse(lis.begin(), lis.end());
        return lis;        
        
    }	
};

