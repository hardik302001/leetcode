//https://leetcode.com/problems/sliding-window-maximum/
// LEAD CODING BY FRAZ, youtube



class Solution {
public:
    // time: O(n), space: O(n)
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxdq;    //front gives max elemnet
        deque<int> mindq;    // front gives minimum element
        int i = 0,j = 0;
        int ans = 0;
        
        while ( i < nums.size()) {
            while (!maxdq.empty() && nums[i] >= nums[maxdq.back()]) maxdq.pop_back();
            while (!mindq.empty() && nums[i] <= nums[mindq.back()]) mindq.pop_back();
            
            maxdq.push_back(i);
            mindq.push_back(i);
            
            // reduce the window size until condition is fulfilled
            if (nums[maxdq.front()] - nums[mindq.front()] > limit) {
                j++;
                if (j > maxdq.front()) maxdq.pop_front();
                if (j > mindq.front()) mindq.pop_front();
            
            }
            else{
                //take in account size, as window satisfy condition
                ans = max(ans, i - j + 1);
                i++;
            }
        }
        return ans;
    }
};