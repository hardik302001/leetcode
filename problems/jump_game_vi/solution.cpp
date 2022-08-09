/*
greedy wont work  (WA)

[0,-1,-2,-3,1]
2

expected -1 (-2 , 1)
got -2 (-1 , -2 , 1)

*/

// ------------------------------------------------------------------

/*
recursion gives tle    O(n^k)
*/

// --------------------------------------------------------------

// dp + memo gives tle too O(n*k) = 10*9

/*
class Solution {
public:
  // dp[i] will denote the maximum score that we can obtain starting from ith index. 
    vector<int>dp = vector<int>(100001, INT_MIN);  // maximum sum till index i      
    // recursive solver which finds max score to reach n-1 starting from ith index
    
    int recur(vector<int>& nums, int k, int i){
        if(dp[i] != INT_MIN) return dp[i];   // already calculated result for index i
	       for(int j = 1; j <= k; j++)          // try jumps of all length and choose the one which maximises the score
		        if(i + j < nums.size())
			        dp[i] = max(dp[i], nums[i] + recur(nums, k, i + j));
	    return dp[i];
    }
    

    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        dp[n-1] = nums[n-1];   // maximum sum from index (n-1) is nums[n-1].
        return recur(nums , k , 0 );
    }
 
};

*/

// ----------------------------------------------------------

//so we use priority queue or deque for the same 
// ULTIMATE EXPLANATION : https://leetcode.com/problems/jump-game-vi/discuss/1261207/Dry-Run-Picture-oror-Dp-with-Explanation-oror-C%2B%2B-oror-Deque-oror-PriorityQueue

// O(nlogk)
// priority solution
/*
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
*/


//----------------------------------------------------------------------


// O(n)
// deque solution
// sliding window maximum
// similar to : https://leetcode.com/problems/constrained-subsequence-sum/
// there we have choice to choose or not choose, but here we have to choose

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n, 0);  // dp[i], gives maximum constrainted subseq sum till ith index
        int ans = dp[0];  
        deque<int> dq;       //max deque, dq.front(), gives max element
        // dec deque
        
        for(int i=0;i<n;i++){
            dp[i] = nums[i]+(dq.empty()?0:dp[dq.front()]);   // we have to choose from front() as dq.front() gives maximum
            
            // Pop from back rear end as we are concerned with max number only
            while(!dq.empty() && dp[dq.back()]<=dp[i]) 
                dq.pop_back();          //pop indexes
            dq.push_back(i);
            
            if(!dq.empty() && dq.front() ==i-k) //If elements are out of range k
                dq.pop_front(); //pop from front
                        
        }

        return dp.back();  // we need maximum answer till last index
    }
};