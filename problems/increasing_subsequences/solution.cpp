class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> seq;
        helper(nums, seq, res, 0);
        
        return vector<vector<int>>(res.begin(), res.end());
    }
    
    void helper(vector<int> &nums, vector<int>& seq, set<vector<int>>& result, int index) {
        if (seq.size() >= 2)
            result.insert(seq);
    
        for (int i=index; i<nums.size(); ++i) {
            if (seq.size() == 0 or nums[i] >= seq.back()) {
                seq.push_back(nums[i]);
                helper(nums, seq, result, i+1);
                seq.pop_back();                       //backtracking
            }
        }
    }
};