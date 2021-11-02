//SLIDING WINDOW + DEQUE
//SIMILAR PROBEM : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/ 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n-k+1,0);
        
        deque<int> dq;

        
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back(); //Pop indexes from rear/back end
            dq.push_back(i);           //push indexes 
        }
        
        for(int i=k;i<n;i++){
            ans[i-k]=nums[dq.front()];
            
            while(!dq.empty() && dq.front()<=i-k) //If elements are out of range k
                dq.pop_front(); //pop from front
            
            //Pop from back rear end as we are concerned with max number only
            while(!dq.empty() && nums[dq.back()]<=nums[i]) 
                dq.pop_back();          //pop indexes
            
            dq.push_back(i);
        }
        ans[n-k]=nums[dq.front()];
        return ans;
    }
};

