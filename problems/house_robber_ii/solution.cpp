//This problem is a little tricky at first glance. However, if you have finished the House Robber problem, this problem can simply be decomposed into two House Robber problems.
// Suppose there are n houses, since house 0 and n - 1 are now neighbors, we cannot rob them together and thus the solution is now the maximum of

// Rob houses 0 to n - 2;
// Rob houses 1 to n - 1.

/* FIRST AC CODE*/
// class Solution {
// public:
    
//     int solve(int l, int r, vector<int>nums, int n){
        
//         vector<int>dp(n,0);
//         dp[l] = nums[l];
//         dp[l+1] = max(nums[l+1],nums[l]);
        
//         for(int i = l+2;i<=r ;i++)
//             dp[i] = max(nums[i] + dp[i-2],dp[i-1]);
    
//         return dp[r];
             
//     }
    
    
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n==1){             //bcz we are initialising dp[1],means n = 2  .......if n == 1, we cant decalare dp[1], bcz size of vector is 1, we cant initialise second eleemnt..
//             return nums[0];
//         }
//         if(n==2){
//             return *max_element(nums.begin(),nums.end());
//         }
     
//         return max(solve(0,n-2, nums,n), solve(1,n-1, nums,n));
//     }
// };


/* SECOND AC CODE */

// class Solution {
// public:
//     int houseRobber(vector<int>& nums) {
//         // dynamic programming - decide each problem by its sub-problems:
//         int dp[nums.size()+1];
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);
//         for (int i=2; i<nums.size(); i++)
//             dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
//         return dp[nums.size()-1];
//     }
    
//     int rob(vector<int>& nums) {
//         // edge cases:
//         if (nums.size() == 0) return 0;
//         if (nums.size() == 1) return nums[0];
//         if (nums.size() == 2) return max(nums[0], nums[1]);
        
//         // either use first house and can't use last      OR    last and not first:
//         vector<int> v1(nums.begin(), nums.end()-1);
//         vector<int> v2(nums.begin()+1, nums.end());
//         return max(houseRobber(v1), houseRobber(v2));
//     }
// };


/* THIRD AC CODE O(1) SPACE: SAME AS HOUSE ROBBER */

class Solution {
public:

    int  houseRob(vector<int>&a , int l ,  int h){
        int oneStepBack = a[l]; 
        int twoStepBack = max(a[l],a[l+1]);
        int c = 0;
        for(int i=l+2 ; i<=h ; i++){
            c = max( oneStepBack+a[i] , twoStepBack);
            oneStepBack = twoStepBack;
            twoStepBack = c;
        }
        return twoStepBack;
    }

    
    

    int rob(vector<int>& a) {
        if(a.size() == 0) return 0;
        if(a.size() == 1) return a[0]; 
        if(a.size() == 2) return max(a[0], a[1]);
        return max( houseRob(a , 0 , a.size()-2) , houseRob(a , 1 , a.size()-1));
    }
};






