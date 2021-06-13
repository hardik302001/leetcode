class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> state(3, 0);
        for (auto &v : triplets) {
            if (v[0] <= target[0] && v[1] <= target[1] && v[2] <= target[2]) {
                state[0] = max(state[0], v[0]);
                state[1] = max(state[1], v[1]);
                state[2] = max(state[2], v[2]);
            }
        }
        return state == target;
    }
};