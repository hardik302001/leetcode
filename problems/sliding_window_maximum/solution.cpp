//SLIDING WINDOW + DEQUE
//SIMILAR PROBEM : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/ 
// also see: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
//also do: https://leetcode.com/problems/jump-game-vi/    , very similar , do check it out!

//also do : https://leetcode.com/problems/constrained-subsequence-sum/



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            // add current
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            
            // remove extra
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();  // subarray size shud be k only
            
            // update answer
            if (i>=k-1) ans.push_back(nums[dq.front()]);  // ==(k-1) , we got subarray of size k
            
        }
        return ans;
    }
};