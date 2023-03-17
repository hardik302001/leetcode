class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
    int count[10001] = {};
    int n = mat.size(), m = mat[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ++count[mat[i][j]];
        }
    }
    for (int k = 1; k <= 10000; ++k) {
        if (count[k] == n) {
            return k;
        }
    }
    return -1;
}
};