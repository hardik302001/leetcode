class Solution {
public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int len = nums.size() * 2;
        for(auto& t : queries) {
            int dec = t[0] % len;
            int left = abs((int)nums.size() - dec);
            
            res.push_back(t[1] < left ? ( dec > nums.size() ? nums[t[1]] : nums[dec + t[1]] ) : -1);
        }
        return res;
    }
};
