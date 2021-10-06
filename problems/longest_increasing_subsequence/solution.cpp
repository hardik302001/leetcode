//O(n**2)
//see prev soln also

//can also be optimised by binary search..I have not done that..see that part in future

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,1);

    /* Compute optimized LIS values in
       bottom up manner */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] and dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
    }
 
    // Return maximum value in lis[]
    return *max_element(dp.begin(), dp.end());
    }
};