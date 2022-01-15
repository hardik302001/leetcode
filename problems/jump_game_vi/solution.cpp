// grreedy wont work  (WA)
// [0,-1,-2,-3,1]
// 2

// expected -1
// got -2

// recursion gives tle
// dp + memo gives tle too O(n*k) = 10*9

// class Solution {
// public:
    
//     vector<int>dp = vector<int>(100001, INT_MIN);      
//     // recursive solver which finds max score to reach n-1 starting from ith index
    
//     int recur(vector<int>& nums, int k, int i){
//         if(dp[i] != INT_MIN) return dp[i];   // already calculated result for index i
// 	    for(int j = 1; j <= k; j++)          // try jumps of all length and choose the one which maximises the score
// 		    if(i + j < nums.size())
// 			    dp[i] = max(dp[i], nums[i] + recur(nums, k, i + j));
// 	    return dp[i];
//     }
    

//     int maxResult(vector<int>& nums, int k) {
//         int n = nums.size();
//         dp[n-1] = nums[n-1];
//         return recur(nums , k , 0 );
//     }
 
// };



//so we use priority queue or deque for the same 
// ULTIMATE EXPLANATION : https://leetcode.com/problems/jump-game-vi/discuss/1261207/Dry-Run-Picture-oror-Dp-with-Explanation-oror-C%2B%2B-oror-Deque-oror-PriorityQueue

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
         priority_queue<pair<int,int>> pq;      
         vector<int> dp(nums.size(),0);
		 
         for(int i=0;i<nums.size();i++)
         {
             while(!pq.empty() && pq.top().second<i-k)
                 pq.pop();
             
             dp[i]=nums[i]+(pq.empty()?0:pq.top().first);
             pq.push({dp[i],i});
         }
         return dp[nums.size()-1];
               
    }
};