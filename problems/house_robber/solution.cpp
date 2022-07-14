// exactly same  ques :maximum sum of non adjacent elements



/*
A robber has 2 options: a) rob current house i; b) don't rob current house.
If an option "a" is selected it means she can't rob previous i-1 house but can safely proceed to the one before previous i-2 and gets all cumulative loot that follows.
If an option "b" is selected the robber gets all the possible loot from robbery of i-1 and all the following buildings.
So it boils down to calculating what is more profitable:

robbery of current house + loot from houses before the previous
loot from the previous house robbery and any loot captured before that
rob(i) = Math.max( rob(i - 2) + currentHouseValue, rob(i - 1) )

*/





//O(n), space = O(n)

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n==1){     ,           //bcz we are initialising dp[1],means n = 2  .......if n == 1, we cant decalare dp[1], bcz size of vector is 1, we cant initialise second eleemnt..
//             return nums[0];
//         }
        
//         vector<int>dp(n,0);
//         dp[0] = nums[0];
//         dp[1] = max(nums[1],nums[0]);
        
//         for(int i = 2;i<n ;i++)
//             dp[i] = max(nums[i] + dp[i-2],dp[i-1]);
    
//         return dp[n-1];
//     }
// };




//  o(n) , space O(1), bcz only 2 variable are changing so we need not create a full array of size n

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1){
            return nums[0];
        }
        
        int a  = nums[0];
        int b = max(nums[1],nums[0]);
        int c;
        for(int i = 2;i<n ;i++){
            c = max(nums[i] + a, b);
            a = b;
            b = c;
        }
        return b;
    }
};