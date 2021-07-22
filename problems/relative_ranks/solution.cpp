class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        
        priority_queue<pair<int,int>> que;
        for (int i = 0; i < n; i++) que.push({nums[i], i});
    
        vector<string> ans(n);
        for (int i = 1; i <= n; i++) {
            int idx = que.top().second; que.pop();
            if (i == 1)       ans[idx] = "Gold Medal";
            else if (i == 2)  ans[idx] = "Silver Medal";
            else if (i == 3)  ans[idx] = "Bronze Medal";
            else              ans[idx] = to_string(i);
        }
        return ans;
    }
};