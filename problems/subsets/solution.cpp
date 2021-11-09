//bitmanipulation
//see prev submission also

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                if ((i) & (1<<j)) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
};