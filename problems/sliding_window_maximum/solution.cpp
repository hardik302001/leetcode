//SLIDING WINDOW + DEQUE
//SIMILAR PROBEM : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/ 




//also do: https://leetcode.com/problems/jump-game-vi/    , very similar , do chcek it out!




//also do : https://leetcode.com/problems/constrained-subsequence-sum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n-k+1,0);
        
        deque<int> dq;       //max deque, dq.front(), gives max element

        
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back(); //Pop indexes from rear/back end
            dq.push_back(i);           //push latest maximum index 
        }
        
        for(int i=k;i<n;i++){
            ans[i-k]=nums[dq.front()];
            //Pop from back rear end as we are concerned with max number only
            while(!dq.empty() && nums[dq.back()]<=nums[i]) 
                dq.pop_back();          //pop indexes
            dq.push_back(i);
            
            
            if(!dq.empty() && dq.front() ==i-k) //If elements are out of range k
                dq.pop_front(); //pop from front
            
        }
        ans[n-k]=nums[dq.front()];
        return ans;
    }
};

