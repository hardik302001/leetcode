// dp
/*
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0;      // we are standing at 0th index
        
        for(int i = 0 ;i<n;i++){
            int next = i + nums[i];
            for(int j = i; j<=min(n , next);j++) dp[j] = min(dp[j], 1 + dp[i]);
        }
        
        return dp[n-1];
    }
};

*/


// greedy

// The main idea is based on greedy.
// Step 1: Let's say the range of the current jump is [left, right], farthest is the farthest position that all positions in [left, right] can reach.
// Step 2: Once we reach to right, we trigger another jump with left = right + 1, right = farthest, then repeat step 1 util we reach at the end.
// BFS LIKE SOLUTION

class Solution{
public:
    int jump(vector<int>&nums){
        int n = nums.size();
        int left = 0;
        int right = 0;
        int farthest = 0;
        int jump = 0;
        while( right < n-1 ) { // we break as it reaches (n-1) index
            for(int i = left; i<=right;i++){ // from out current position we can jump from [left, right] only. 
                farthest = max(farthest , i + nums[i]);
            }
            left = right +  1;
            right = farthest;
            jump++;
        }
        
        return jump;

    }   
};