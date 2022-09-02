/*
Time Complexity: O(N*K) + O(N)
k = target sum
Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved and we are running a for loop for ‘N’ times to calculate the total sum
----------------------------------------------------------------------------
Space Complexity: O(N*K) + O(N)
Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).

*/


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
        if(idx>n) return 0;
        if(cur>sum) return 0;
        if(idx==n){
            if(cur==sum) return 1;
            else         return 0;
        }
        if(dp[idx][cur]!=-1) return dp[idx][cur];
        bool ans =  isSubsetSum(idx+1, cur , nums , n , sum) or isSubsetSum(idx+1 , cur + nums[idx] , nums, n,  sum);
        
        return dp[idx][cur] = ans;
    }
};




