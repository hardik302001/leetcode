// Iterative

// Using [1, 2, 3] as an example, the iterative process is like:

// Initially, one empty subset [[]]
// Adding 1 to []: [[], [1]];
// Adding 2 to [] and [1]: [[], [1], [2], [1, 2]];
// Adding 3 to [], [1], [2] and [1, 2]: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }
}; 