class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        for (int i = 1; i < n; i++) {
            costs[i][0] += std::min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += std::min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += std::min(costs[i - 1][0], costs[i - 1][1]);
        }
        return (n == 0) ? 0 : (std::min(costs[n - 1][0], std::min(costs[n - 1][1], costs[n - 1][2])));
    }
};