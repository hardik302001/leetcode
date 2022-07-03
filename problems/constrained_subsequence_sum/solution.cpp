// same as sliding window maximum
// same as jump game 6 

// O(n): deque solution
// O(nlogn): pq soln can also be done

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int> dp = nums;  // dp[i], gives maximum constrainted subseq sum till ith index
        int ans = dp[0];  
        deque<int> dq;       //max deque, dq.front(), gives max element
        
        for(int i=0;i<n;i++){
            dp[i] = max(dp[i] , nums[i]+(dq.empty()?0:dp[dq.front()]));   //updating dp[i], if to choose it(then update) or not
            
            //Pop from back rear end as we are concerned with max number only
            while(!dq.empty() && dp[dq.back()]<=dp[i]) 
                dq.pop_back();          //pop indexes
            dq.push_back(i);
            
            if(!dq.empty() && dq.front() ==i-k) //If elements are out of range k
                dq.pop_front(); //pop from front
            
            
            ans = max(ans , dp[i]);    // taking max of all dp[i]
        }
        

        return ans;
    }
};