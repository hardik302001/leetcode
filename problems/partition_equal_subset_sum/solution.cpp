class Solution {
public:
    
    int dp[201][20001];
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto a : nums) // Sum up the array
            sum += a;
        
        if (sum % 2) // If the sum is odd - we can never find two equal partitions
            return false;
        
        sum /= 2;
        memset(dp , -1 , sizeof dp);
        bool ans = isSubsetSum(0 , 0 , nums, nums.size(), sum);
        return ans;
    }
    
    bool isSubsetSum(int idx ,  int cur , vector<int>&nums, int n, int sum)
    {
        if(idx>=n) return false;
        if(cur>sum) return false;
        
        if(cur==sum) return true;
        if(dp[idx][cur]!=-1) return dp[idx][cur];
        bool ans =  isSubsetSum(idx+1, cur , nums , n , sum) or isSubsetSum(idx+1 , cur + nums[idx] , nums, n,  sum);
        
        return dp[idx][cur] = ans;
    }
};