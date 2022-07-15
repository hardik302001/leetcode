// also see: https://leetcode.com/problems/best-sightseeing-pair/submissions/

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int mi = INT_MAX;
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans , nums[i]-mi);
            mi = min(nums[i], mi);
        }
        
        return ans;
    }
}; 