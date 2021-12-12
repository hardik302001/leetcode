class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto a : nums) // Sum up the array
            sum += a;
        
        if (sum % 2) // If the sum is odd - we can never find two equal partitions
            return false;
        
        sum /= 2;
        
        bool ans = isSubsetSum(nums, nums.size(), sum);
        return ans;
    }
    
    bool isSubsetSum(vector<int>&set, int n, int sum)
    {
        // The value of subset[i][j] will be true if
        // there is a subset of set[0..j-1] with sum
        // equal to i
        bool subset[n + 1][sum + 1];

        // If sum is 0, then answer is true
        for (int i = 0; i <= n; i++)
            subset[i][0] = true;

        // If sum is not 0 and set is empty,
        // then answer is false
        for (int i = 1; i <= sum; i++)
            subset[0][i] = false;

        // Fill the subset table in bottom up manner
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j < set[i - 1])
                    subset[i][j] = subset[i - 1][j];
                if (j >= set[i - 1])
                    subset[i][j] = subset[i - 1][j]
                                   || subset[i - 1][j - set[i - 1]];
            }
        }


        return subset[n][sum];
    }
};