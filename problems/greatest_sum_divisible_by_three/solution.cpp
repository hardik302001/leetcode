// dp , but why not greedy?
// here we dont need the count, we need the maximum sum, so we need to consider values
// we can make 3 using 3 elements with v%3==2, or 3 elements with v%3==1 or 1 with v%3==1 and 1 with v%3==2
// so we need to cover all cases


// recursion (2^n)
/*
class Solution {
public:
    
    int recur(int i , vector<int>&nums, int r){
        if(i==int(nums.size())){
            if(r==0){  // sum is div by 3
                return 0;
            }else{     // return INT_MIN, at end we will get max sum = 0, bcz if we ignore all elements
                return INT_MIN;
            }
        }
        
        int consider = nums[i] + recur(i+1 , nums, (r+nums[i])%3);   // updated rem
        int ignore = recur(i+1 , nums, r);             // same rem
        
        return max(consider , ignore);
        
    }
    
    int maxSumDivThree(vector<int>& nums) {
        int rem = 0;
        return recur(0 , nums, rem);
    }
};
*/

// -----------------------------------------------------------------------------------------
// memoise, dp , O(3*n)




class Solution {
public:  
    vector<vector<int>>dp = vector<vector<int>>(40001, vector<int>(3, -1));
    vector<vector<int>>vis = vector<vector<int>>(40001, vector<int>(3, 0));
    int recur(int i , vector<int>&nums, int r){
        if(i==int(nums.size())){
            if(r==0){  // sum is div by 3
                return 0;
            }else{     // return INT_MIN, at end we will get max sum = 0, bcz if we ignore all elements
                return INT_MIN;
            }
        }
        
        if(vis[i][r]==1) return dp[i][r];
        
        int consider = nums[i] + recur(i+1 , nums, (r+nums[i])%3);   // updated rem
        int ignore = recur(i+1 , nums, r);             // same rem
        
        vis[i][r] = 1;
        return dp[i][r] = max(consider , ignore);
        
    }
    
    int maxSumDivThree(vector<int>& nums) {
      
        int rem = 0;
        return recur(0 , nums, rem);
    }
};